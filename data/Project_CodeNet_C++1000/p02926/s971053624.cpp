#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

#define ll long long
#define ld long double

#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repb(i,a,b) for(ll i=a;i>=b;i--)
#define repA(i,A)   for(auto i:A)

#define err() cout<<"=================================="<<endl;
#define errA(A) for(auto i:A)   cout<<i<<" ";cout<<endl;
#define err1(a) cout<<#a<<" "<<a<<endl
#define err2(a,b) cout<<#a<<" "<<a<<" "<<#b<<" "<<b<<endl
#define err3(a,b,c) cout<<#a<<" "<<a<<" "<<#b<<" "<<b<<" "<<#c<<" "<<c<<endl
#define err4(a,b,c,d) cout<<#a<<" "<<a<<" "<<#b<<" "<<b<<" "<<#c<<" "<<c<<" "<<#d<<" "<<d<<endl

#define mp make_pair
#define pb push_back
#define all(A)  A.begin(),A.end()
#define allr(A)	A.rbegin(),A.rend()
#define ft first
#define sd second

#define pll pair<ll,ll>
#define V vector<ll>
#define S set<ll>
#define VV vector<V> 
#define Vpll vector<pll>

#define endl "\n"

const ll logN = 20;
const ll M = 1000000007;
const ll INF = 1e12;
#define PI 3.14159265

const ll N = 100005;

const ld to_degrees = 180.0/PI;

ld theta(pll a){
	ld x = a.ft;
	ld y = a.sd;
	ld theta;
	if(x==0){
		if(y>0)	theta = PI/2;
		else theta = -PI/2;
		return theta;
	}
	theta = atan(abs(y/x));
	if(x>0){
		if(y>0)	;
		else	theta = -theta;
	}
	else{
		if(y>0)	theta = PI - theta;
		else theta = -(PI - theta);
	}
	return theta;
}


bool cmp(pll a, pll b){
	ld theta_a = theta(a);
	ld theta_b = theta(b);
	if(theta_a < theta_b)	return 1;
	else return 0;
}

pll A[105];

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 	ll n;
 	cin>>n;
 	rep(i,0,n){
 		ll x,y;
 		cin>>x>>y;
 		A[i] = {x,y};
 	}
 	sort(A,A+n,cmp);
 	ld ans=0;
 	rep(i,0,n){
 		ll j=i;
 		ll x=A[i].ft;
 		ll y=A[i].sd;
 		do{
 			ld cnt = sqrt(x*x+y*y);
 			ans = max(ans,cnt);
 			j = (j+1)%n;
 			x += A[j].ft;
 			y += A[j].sd;
 		}while(i!=j);
 	}
 	cout<<fixed<<setprecision(10)<<ans<<endl;
    return 0;
}