#include<bits/stdc++.h>
using namespace std;
using ll  = long long;
using vl  = vector<ll>;
using vi  = vector<int>;
#define _GLIBCXX_DEBUG
#define IO_STREAM cin.tie(0);ios::sync_with_stdio(false)
#define all(x) x.begin(),x.end()
#define rep(i,sta,end) for(int i=sta;i<end;++i)
#define lcm(a,b) (a)/__gcd((a),(b))*(b)
#define pb push_back
const ll INF = 1000000000000000;
const ll MOD = 1000000007;
const double PI = acos(-1);
//||
#define DBG(a,b,c,d) //cout<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<endl
//DBG("","","","");

int main(){
	IO_STREAM;
	int N;	cin>>N;
	vector<pair<double,double>> a(N);
	rep(i,0,N){
		cin>>a[i].first;
		cin>>a[i].second;
	}
	double ans=0;
	int cnt=0;
	sort(all(a));
	do{
		double temp=0;
		rep(i,0,N-1){
			temp+=sqrt(		(a[i].first-a[i+1].first)*(a[i].first-a[i+1].first)
						+	(a[i].second-a[i+1].second)*(a[i].second-a[i+1].second)
					);
		}
		DBG(temp,"","","");
		DBG(a[0].first,a[1].first,a[2].first,"");
		DBG(a[0].second,a[1].second,a[2].second,"");
		ans+=temp;
		cnt++;
	}while(next_permutation(all(a)));
	
	DBG(ans,cnt,"","");
	ans/=cnt;
	cout << fixed << setprecision(9);
	cout<<ans<<endl;
	return 0;
}
