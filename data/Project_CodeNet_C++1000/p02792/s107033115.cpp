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
    vector<vector<int>> v(10,vector<int>(10));
    int n,t=0;cin>>n;
    repp(i,1,n) {
        int j=i,k=j%10;
        while(j>9) {
            j/=10;
        }
        v[j][k]++;
    }
    repp(i,1,9) repp(j,1,9)
    t+=v[i][j]*v[j][i];
    cout<<t;   
}