#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define P pair<int,int>
#define fi first
#define se second
#define rep(i,n) for(int i=0;i<n;i++)
#define INF 1000000000
#define MOD 1000000007
#define all(v) v.begin(),v.end()
#define pb push_back
int dx[]={0,1,0,-1},dy[]={1,0,-1,0};
int kaijo[200010];
struct edge{int to,cost;};
int gcd(int a,int b){
	if(b==0)return a;
	return gcd(b,a%b);
}
int lcm(int a,int b){
	return a/gcd(a,b)*b;
}
bool prime(int a){
	if(a==1)return false;
	for(int i=2;i*i<=a;i++){
		if(a%i==0)return false;
	}
	return true;
}
bool kosa(double ax,double ay,double bx,double by,double cx,double cy,double dx,double dy){//線分の交差判定
	double ta=(cx-dx)*(ay-cy)+(cy-dy)*(cx-ax);
	double tb=(cx-dx)*(by-cy)+(cy-dy)*(cx-bx);
	double tc=(ax-bx)*(cy-ay)+(ay-by)*(ax-cx);
	double td=(ax-bx)*(dy-ay)+(ay-by)*(ax-dx);
	return tc*td<0&&ta*tb<0;
}
void init_fact(int n){
	kaijo[0]=1;
	for(int i=1;i<=n;i++){
		kaijo[i]=kaijo[i-1]*i;
		kaijo[i]%=MOD;
	}
}
int modpow(int a,int b){
	if(b==0)return 1;
	if(b%2)return modpow(a,b-1)*a%MOD;
	int memo=modpow(a,b/2);
	return memo*memo%MOD;
}
int comb(int a,int b){
	if(b>a)return 0;
	if(a==b)return 1;
	return kaijo[a]*modpow(kaijo[a-b],MOD-2)%MOD*modpow(kaijo[b],MOD-2)%MOD;
}
int g(int x){
	x=modpow(x,MOD-2);
	return x;
}
int n,l,r,a[200010],ans=1;
string s;
signed main(){
	cin>>n>>s;
	init_fact(200000);
	rep(i,2*n){
		if(i==0||i==2*n-1){
			if(s[i]=='W'){
				puts("0");
				return 0;
			}
		}
		if(i==0)a[i]=1;
		else{
			if(s[i]==s[i-1])a[i]=1-a[i-1];
			else a[i]=a[i-1];
		}
	}
	rep(i,2*n){
		if(a[i]==0){
			ans*=l-r;
			ans%=MOD;
		}
		if(a[i]==1)l++;
		else r++;
	}
	ans*=kaijo[n];
	ans%=MOD;
	if(l==r)cout<<ans<<endl;
	else puts("0");
	return 0;
}
