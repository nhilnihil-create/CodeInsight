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
    int n, d, rta = 0;
    cin >> n >> d;
    int a[n][d];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < d; j++){
            cin >> a[i][j];
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            ll sum = 0, aux;
            for(int k = 0; k < d; k++){
                sum += (a[i][k]-a[j][k])*(a[i][k]-a[j][k]);
            }
            aux = sqrt(sum);
            if(aux*aux == sum) rta++;
        }
    }
    cout << rta << endl;
    return 0;
}

