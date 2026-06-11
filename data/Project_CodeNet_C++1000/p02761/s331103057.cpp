//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pp pair<int,int>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define ld long double
#define al(a) (a).begin(),(a).end()
#define mk make_pair
#define check cout<<"?"<<endl;

ll MOD=1000000007;
ll mod=998244353;
int inf=1000001000;
ll INF=1e18+5;

int main(){
    int n,m,l=1,r=1; cin>>n>>m;
    vector<int> num(n,0),s(m,0),c(m,0);
    rep(i,m) cin>>s[i]>>c[i];
    if(n==1) l=0;
    else rep(i,n-1) l*=10;
    rep(i,n) r*=10; r--;
    for(int i=l;i<=r;i++){
        int N=i,J=1;
        rep(j,n){
            num[n-j-1]=N%10; N/=10;
        }
        rep(j,m)if(num[s[j]-1]!=c[j]) J=0;
        if(J){
            cout<<i<<endl; return 0;
        }
    }
    cout<<-1<<endl;
}
