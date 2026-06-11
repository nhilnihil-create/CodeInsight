#include <bits/stdc++.h>
#define rep(i,l,r) for (int i=l,i##end=r;i<=i##end;++i)
#define per(i,r,l) for (int i=r,i##end=l;i>=i##end;--i)
#define rep0(i,r) for (int i=0,i##end=r;i<i##end;++i)
#define pr pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define ll long long
#define pb push_back
using namespace std;
const int N=1e6+6;
int main(){
    ll n,a,b; cin>>n>>a>>b;
    if (b%2==a%2) cout<<(max(a,b)-min(a,b))/2<<endl;
    else cout<<min((a+b-1)/2,(2*n-(a+b)+1)/2)<<endl;
}
