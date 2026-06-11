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
    for(int i = 1; i <= n; i++){
        aux = log10(i)+1;
        if(aux%2) rta++;
    }
    cout << rta << endl;
    return 0;
}

