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
const double pi=acos(-1);
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
//cout << fixed << setprecision(12);
ll n,p; cin>>n>>p;
string s;
cin>>s;
reverse(all(s));
ll ca=0;
ll a[p]={};
ll ten=1;
if(p == 2){
ll k = n;
rep(i,n){
if((s.at(i)-'0')%2==0){
ca+=k;}
k--;}
cout << ca << endl;}
else if(p == 5){
ll k = n;
rep(i,n){
if((s.at(i)-'0')==0||(s.at(i)-'0')==5){
ca+=k;}
k--;}
cout << ca << endl;}
else{
rep(i,n){
ca +=((s.at(i)-'0')*ten);
ca %=p;
//cout << ca << endl;  
a[ca]++;
ten*=10;
ten%=p;}
ca=0;
ten=1;
a[0]++;
repl(i,0,p){
ca+=a[i]*(a[i]-1)/2;}
cout << ca << endl;}}

