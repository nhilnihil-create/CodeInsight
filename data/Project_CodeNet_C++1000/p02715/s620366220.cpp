#include<bits/stdc++.h>
using namespace std;
int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};
#define ull unsigned long long int
#define ll long long int
#define MAX 1000000007
//1e9+7
#define pll pair<ll,ll>
#define pii pair<int,int>
#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define FO ifstream fin("a.in");ofstream fout("a.out");
#define TEST ll t;cin>>t;while(t--)
#define all(x) (x).begin(),(x).end()
#define mset0(x) memset((x), 0, sizeof((x)));
#define mset1(x) memset((x), -1, sizeof((x)));

bool prime[10000];
void era(){
    memset(prime,true,sizeof prime);
    for(ll p=2;p*p<=10000;p++){
        if(prime[p]){
            for(ll q=p*p;q<=10000;q+=p){
                prime[q]=false;
            }
        }
    }

    return;
}
bool is_prime(ll x){
    if(x==1) return(false);
    if(x==2 || x==3) return(true);
    if(x%2==0) return(false);
    if(x%3==0) return(false);
    for(ll p=5;p*p<=x;p++){
        if(x%p==0) return(false);
    }
    return(true);
}
ll fac[200001],finv[200001];
ll power(ll a,ll b){
    a%=MAX;
    ll ans=1;
    while(b){
        if(b&1) ans=(ans*a)%MAX;
        b/=2;
        a=(a*a)%MAX;
    }
    return(ans%MAX);
}
ll inverse(ll a){
    return((power(a,MAX-2))%MAX);
}
ll ncr(ll n, ll r){
    ll p1=finv[n-r];
    ll p2=finv[r];

    return((((fac[n]*p1)%MAX)*p2)%MAX);


}
bool solve(ll n,ll arr[]){
    ll sum=0;
    for(ll i=0;i<n;i++){
        sum+=arr[i];
        if(sum<=0) return(false);
    }
    sum=0;
    for(ll i=n-1;i>=0;i--){
        sum+=arr[i];
        if(sum<=0) return(false);
    }
    return(true);
}
struct Node{
    ll l,r,w;
}arr[5001];

string cmp(string a,string b){
    if(a.size()>b.size()) return(a);
    if(b.size()>a.size()) return(b);
    int n=a.size();
    for(int i=0;i<n;i++){
        if(a[i]==b[i]) continue;
        if((a[i]-'0')>(b[i]-'0')) return(a);
        else return(b);
    }
    return(a);
}

int main(){
    IO
    ll n,k;
    cin>>n>>k;
    ll w[k+1];
    memset(w,0,sizeof w);
    for(ll gcd=k;gcd>=1;gcd--){
        ll a=k/gcd;
        ll a_b=power(a,n);
       // cout<<a_b<<endl;
        w[gcd]=a_b;
        for(ll mul=2*gcd;mul<=k;mul+=gcd){
            w[gcd]-=w[mul];
            if(w[gcd]<0) w[mul]+=MAX;


        }
    }
    ll sum=0;
   // for(ll i=1;i<=k;i++) cout<<w[i]<<" ";
   // cout<<endl;
    for(ll i=1;i<=k;i++){
        sum+=(i*w[i])%MAX;
        sum%=MAX;
    }
    cout<<sum%MAX;
    return(0);
}
