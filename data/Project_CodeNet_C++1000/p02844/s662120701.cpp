#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define puts(i) cout<<i<<endl
#define pi 3.14159265358979323846264338
#define pb push_back
#define mp make_pair
#define inf 10000
using ll = long long;
using P = pair<int,int>;
using Pll = pair<ll,ll>;

ll divisor=1000000007;

int main(){
	int n;
	string s;
	cin>>n>>s;
	int ans=0;
	rep(i,1000){
		vector<int> v;
		int a=i;
		rep(j,3){
			v.pb(a%10);
			a/=10;
		}
		a=2;
      	
		rep(j,n){
			if(s[j]=='0'+v[a])a--;
          	if(a==-1)break;
		}
		if(a==-1)ans++;
	}
  puts(ans);
}
