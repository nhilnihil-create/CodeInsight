#include<bits/stdc++.h>
#define M 1000000007
#define pi ld(acos(-1.0))
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define Rep(i,n) for(int i=1;i<(int)(n);i++)
#define repp(i,a,b)  for(int i=a;i<=(int)(b);i++)
#define Repp(i,a,b)  for(int i=a;i>=(int)(b);i--)
#define cs ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fi first
#define se second
#define ii pair<int,int>
#define bye(x) {cout<<x;return 0;}
typedef long long ll;
typedef long double ld;
using namespace std;

int main() {
    cs
    int n,m,x,y;cin>>n>>m;
    x=1;y=m&1?m:m+1;
    while(x!=m/2+1) {
        cout<<x<<' '<<y<<'\n';
        x++;y--;
    }
    x=m&1?m+1:m+2;
    y=2*m+1;
    while(x<y) {
        cout<<x<<' '<<y<<'\n';
        x++;y--;
    }
    
}