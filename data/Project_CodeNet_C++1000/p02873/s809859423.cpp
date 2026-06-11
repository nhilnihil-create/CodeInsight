#include<bits/stdc++.h>
#include<unistd.h>
using namespace std;
#define pb(x) push_back(x);
typedef long long  int ll;
ll mod = 998244353;
ll hmaxii=0;
vector<ll>values[2*100000+1];
ll MAXN = 2*100000+1;
ll spf[2*100000+1];
//vector<ll>values[];
ll diff,x,y,z;
ll flag=1;ll price[1001][1001];

ll gcd(ll a,ll b) { return b?gcd(b,a%b):a; }



void solution(){
    ll n;
    //cin>>n;
    ll ans=0;
    string ss;
    cin>>ss;
    n=ss.length();
    ll right[n+1];
    int temp=0;
    ll left[n+1];
    left[0]=0;
    for(int i=0;i<n;i++){
        if(ss[i]=='<'){
            temp++;
        }
        else{
            temp=0;
        }
        left[i+1]=temp;
    }
    right[n]=0;temp=0;
    for(int i=n-1;i>=0;i--){
        if(ss[i]=='>'){
            temp++;
        }
        else{
            temp=0;
        }
        right[i]=temp;
    }
    for(int i=0;i<=n;i++){
        ans+=max(right[i],left[i]);
    }
    cout<<ans<<endl;
}


int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //sieve();
    /*ll powe[64];
    powe[0]=1;
    ll i=1;
    while(i<64){
        powe[i] = powe[i-1]*2;
        i++;
    }*/
    ll t;
    //cin>>t;
    t=1;
    while(t--){
        solution();
    }
    return 0;
}
