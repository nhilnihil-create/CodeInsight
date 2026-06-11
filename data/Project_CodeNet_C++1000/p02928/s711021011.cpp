
#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef unsigned long long int ulli;
#define vec(s) vector<s>;
#define vvec(s) vector<vector<s>> ;
typedef vector<lli> vi;
typedef vector<vi> vvi;
typedef pair<lli,lli> pii;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define YN(x) cout<<(bool x?"Yes":"No")<<endl;
#define out(s) cout<<s<<endl;
#define pb(s) push_back(s);
#define sp " ";
#define INF 10000000000
#define all(s) s.begin(),s.end()
void vout(vi v){
    for(int i=0;i<v.size();i++)
    cout<<"T"<<v.at(i)<<endl;
}
int main(){
    lli mod=1000000007;
    lli n,k,ans=0;
    cin>>n>>k;
    vi ov;
    vi num(n);
    map<lli,lli> ovn;
    vi a(n);
    rep(i,n) {
        cin>>a[i];
        ov.push_back(a[i]);
    }
    rep(i,n){
        lli now=0;
        for(lli j=i+1;j<n;j++){
            if(a[i]>a[j]){
                now++;
            }
        }
        num[i]=now;
    }
    sort(all(ov));
    reverse(all(ov));
    rep(i,n){
        if(!ovn.count(ov[i])){
            lli t=0;
            while(i+t+1<n&&ov[i]==ov[i+t+1]){
                t++;
            }
            ovn[ov[i]]=n-i-t-1;
        }
    }
    rep(i,n){
        ans+=num[i]*k;
        ans%=mod;
        lli sum=((k*(k-1))/2);
        sum%=mod;
        ans+=ovn[a[i]]*sum;
        ans%=mod;
    }
    out(ans);
}