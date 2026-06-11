#include <bits/stdc++.h>

using namespace std;

#define rep(i,n) for(int i=0;i<(n);i++)
#define repa(i,a,n) for(int i=(a);i<(n);i++)
#define rrep(i,n) for(int i=n-1;i>=0;i--)
#define rrepa(i,a,n) for(int i=n-1;i>=(a);i--)
#define all(a) (a).begin(),(a).end()
#define MOD 1000000007
#define maxs(a,b) a=max(a,b);
#define mins(a,b) a=min(a,b);

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;

int main(){
    
    string s;
    cin>>s;
    
    int n=s.length(),r=0,l=0,ir=0,il;
    s.push_back('R');
    vi ans(n);

    rep(i,n+1){
        if(l==0){
            if(s[i]=='R'){
                ir=i;
                r++;
            }else{
                il=i;
                l++;
            }
        }else{
            if(s[i]=='R'){
                ans[ir]=((r+1)/2) + (l/2);
                ans[il]=((l+1)/2) + (r/2);
                ir=i;
                r=1;
                l=0;
            }else{
                l++;
            }
        }
    }

    rep(i,n)cout<<ans[i]<<" ";
    cout<<"\n";

    return 0;
}
