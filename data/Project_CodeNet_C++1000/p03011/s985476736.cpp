#include <bits/stdc++.h>

using namespace std;

#define rep(i,n) for(int i=0;i<(n);i++)
#define repa(i,a,n) for(int i=(a);i<(n);i++)
#define rrep(i,n) for(int i=(n)-1;i>=0;i--)
#define rrepa(i,a,n) for(int i=(n)-1;i>=(a);i--)
#define all(a) (a).begin(),(a).end()
#define MOD 1000000007
#define maxs(a,b) a=max(a,b);
#define mins(a,b) a=min(a,b);
#define max3(a,b,c) max(a,max(b,c)) 
#define mix3(a,b,c) mix(a,mix(b,c))
#define pairi pair<int,int>

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<double> vd;
typedef vector<vd> vvd;

int main(){
   
    int p,q,r;
    cin>>p>>q>>r;

    int ans=p+q+r;
    ans-=max(p,max(q,r));

    cout << ans << endl;
    
    return 0;
}
