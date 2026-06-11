#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define INF 1e9+7
#define rep(i,n) for(ll i=0;i<n;i++)
#define pii pair<int,int>
#define pll pair<ll,ll>
const int maxn = 1000000;
ll mod = INF;

int a,b;

int main(){
    cin >> a>>b;
    for(int i=1;i<=10000;i++){
        if(i*108/100-i==a&&i*110/100-i==b){
            cout << i<<endl;
            return 0;
        }
    }
    cout << -1<<endl;
    return 0;
}