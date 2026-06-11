#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0;i<(n);i++)
#define rep2(i,a,n) for(int i=a;i<n;i++)
#define been(ix) (ix).begin(),(ix).end()
using namespace std;
typedef long long ll; 
typedef vector<int> vi;
typedef vector<long long> vl;
const ll INFL = 1e18;
const int INF = 1001001001; 
typedef pair<int,int> P;
#define foreach(ix,i) for(auto& (ix) : (i))
typedef long double ld;
const int mod =1000000007;
int main(){
    int n;cin>>n;
    int a[n];
    int c[3];
    rep(i,n)cin>>a[i];
    rep(i,3)c[i]=0;
    ll ans =1;
    rep(i,n){
        int cnt =0;
        bool f =true;
        if(a[i]==c[0]){cnt++;c[0]++;f=false;}
        if(a[i]==c[1]){
            cnt++;
            if(f)c[1]++;
            f=false;
        }
        if(a[i]==c[2]){
            cnt++;
            if(f)c[2]++;
            f=false;
        }
        if(f){
            cout<<0<<endl;
            return 0;
        }
        ans*=cnt;
        ans%=mod;
    }
    cout<<ans<<endl;

}
