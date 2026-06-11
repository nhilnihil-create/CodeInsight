#include <bits/stdc++.h>
using namespace std;
#define fastIO ios::sync_with_stdio(0), cin.tie(0)
#define endl '\n'
#define ft first
#define sd second
#define pb push_back
#define pob pop_back()
#define pf push_front
#define pof pop_front()
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<char,char> pcc;
typedef pair<long long,long long> pll;

int main() {
    fastIO;
    int n, aux, rta = 0;
    cin >> n;
    int a[n], b[n], c[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        cin >> b[i];
    }
    for(int i = 0; i < n-1; i++){
        cin >> c[i];
    }

    rta += b[a[0]-1];
    for(int i = 1; i < n; i++){
        rta += b[a[i]-1];
        if(a[i] - a[i-1] == 1){
            rta += c[a[i-1]-1];
        }
    }
    cout << rta << endl;
    return 0;
}

