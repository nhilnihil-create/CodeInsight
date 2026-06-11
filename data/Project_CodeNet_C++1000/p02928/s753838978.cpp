#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i=0;i<n;i++)
#define repl(i,l,r) for(ll i=(l);i<(r);i++)
#define per(i,n) for(ll i=n-1;i>=0;i--)
#define perl(i,r,l) for(ll i=r-1;i>=l;i--)
#define fi first
#define se second
#define pb push_back
#define ins insert
#define all(x) (x).begin(),(x).end()
using vl=vector<ll>;
using vvl=vector<vector<ll>>;
const ll MOD=1000000007;
const ll MOD9=998244353;
const int inf=1e9+10;
const ll INF=4e18;
const ll dy[8]={1,0,-1,0,1,1,-1,-1};
const ll dx[8]={0,-1,0,1,1,-1,1,-1};
using Graph = vector<vector<int>>;
const ll mod=1000000007;
const int MAX_N = 1000;         // n の最大値
 
double nCk(int n, int k) {
double res=1.0;
for(int i=0; i<n; i++){
res*=0.5;}
for(int i=0; i<k; i++){
res*=(double)(n-i);
res/=(double)(k-i);
}
return res;}
 
int main() {
ll n,k;
cin>>n>>k;
ll ca=0;
ll q=0,w=0;
if(k%2==0){
q = k/2;
q = q*(k+1);
q%=MOD;
w = k/2;
w = w*(k-1);
w%=MOD;}
else{
q = (k+1)/2;
q = q*k;
q%=MOD;
w = (k-1)/2;
w = w*k;
w%=MOD;}
ll a[n]={},b[2005]={},c[n]={},d[n]={};
rep(i,n){
cin>>a[i];
b[a[i]]++;}
rep(i,n){
rep(k,n){
if(a[i]>a[k]){
if(i<k){
c[i]++;}
else{d[i]++;}
}
}}

for(ll i=0; i<n; i++){
if(k%2==0){
ca += q*c[i];
ca%=MOD;
ca += w*d[i];
ca%=MOD;
}
else{
ca += q*c[i];
ca%=MOD;
ca += w*d[i];
ca%=MOD;
}
}
cout << ca << endl;}
