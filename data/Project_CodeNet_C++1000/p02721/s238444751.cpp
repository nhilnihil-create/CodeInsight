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
    int n,k,c; cin>>n>>k>>c;
    string s; cin>>s;
    vector<int> dp_l(n,0),dp_r(n,0);
    int cur=0,last=-inf;
    rep(i,n){
        if(s[i]=='x'){
            dp_l[i]=cur; continue;
        }
        if(i-last>c){
            cur++; last=i;
        }
        dp_l[i]=cur;
    }
    cur=0,last=inf;
    for(int i=n-1;i>=0;i--){
        if(s[i]=='x'){
            dp_r[i]=cur; continue;
        }
        if(last-i>c){
            cur++; last=i;
        }
        dp_r[i]=cur;
    }
    rep(i,n){
        if(s[i]=='x') continue;
        int t=0,l=0,r=i-1,ce;
        if(i==0) l=-c;
        else{
            while(l!=r){
                ce=(l+r)/2;
                if(dp_l[ce]==dp_l[i-1]) r=ce;
                else l=ce+1;
            }
            t+=dp_l[i-1];
        }
        if(i==n-1 && t<k){
            cout<<i+1<<endl; break;
        }
        if(l+c+1<n) t+=dp_r[max(l+c+1,i+1)];
        if(t==k-1){
            int T=0;
            if(i>0) T+=dp_l[i-1];
            T+=dp_r[i];
            if(T==k) cout<<i+1<<endl;
        }
    }
}