#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define INF 1e9+7
#define rep(i,n) for(ll i=0;i<n;i++)
const int maxn = 1000000;
ll mod = INF;

ll gcd(ll a,ll b){
    if(a<b)swap(a,b);
    if(b==0)return a;
    else return gcd(b,a%b);
}

int main(){
    ll a,b;
    cin >> a>>b;
    cout << a*b/gcd(a,b)<<endl;
    return 0;
}