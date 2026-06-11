#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define INF 1e9+7
#define rep(i,n) for(ll i=0;i<n;i++)
#define pii pair<int,int>
#define pll pair<ll,ll>
const int maxn = 1000000;
ll mod = INF;

double L;

int main(){
    cin >> L;
    cout << fixed<<setprecision(12)<<(L/3)*(L/3)*(L/3)<<endl;    
    return 0;
}