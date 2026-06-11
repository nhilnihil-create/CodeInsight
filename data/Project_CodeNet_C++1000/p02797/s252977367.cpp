#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0;i<n;i++)
#define rep2(i,a,n) for(int i=a;i<n;i++)
#define been(ix) (ix).begin(),(ix).end()
using namespace std;
typedef long long ll; 
typedef vector<int> vi;
typedef vector<long long> vl;
const ll INFL = 1e18;
const int INF = 1001001001; 
typedef pair<int,int> P;
#define foreach(ix,i) for(auto& (ix) : (i))
typedef long double ld;
const int mod =1000000007;
const double PI = acos(-1);

int main(){
	ll n,k,s;
	cin>>n>>k>>s;
	vl ans;
	rep(i,k)ans.push_back(s);
	int a=0;
	rep(i,sqrt(s)+2){
		if(i==0)continue;
		if(s%i!=0){
		a=i;
		break;
		}
	}
	if(a==0)a=1;
	rep(i,n-k)ans.push_back(a);
	rep(i,n-1)cout<<ans[i]<<' ';
	cout<<ans[n-1]<<endl;
}