#include <bits/stdc++.h>

using namespace std;

#define rep(i,n) for(int i=0;i<(n);i++)
#define repa(i,a,n) for(int i=(a);i<(n);i++)
#define rrep(i,n) for(int i=n;i>=0;i--)
#define rrepa(i,a,n) for(int i=n;i>=(a);i--)
#define all(a) (a).begin(),(a).end()
#define MOD 1000000007
#define maxs(a,b) a=max(a,b)
#define mins(a,b) a=min(a,b)
#define vc vector

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef pair<int,int> pi;

int main(){
   
    int t1,t2;
    ll a1,a2,b1,b2;
    cin>>t1>>t2>>a1>>a2>>b1>>b2;

    ll d1=t1*(a1-b1),d2=t2*(a2-b2),d=abs(d2)-abs(d1);

    if(d1>0&&d2>0 || d1<0&&d2<0 || d<0){
        cout<<0<<endl;
        return 0;
    }
    if(d==0){
        cout<<"infinity"<<endl;
        return 0;
    }

    if(d1<0)d1*=-1;
    if(d<0)d*=-1;

    ll c=(d1+d-1)/d;

    ll ans=2*c-1;
    if(c*d==d1)ans++;

    cout<<ans<<endl;
    
    return 0;
}