#include<bits/stdc++.h>
using namespace std;
#define all(a)  (a).begin(),(a).end()
typedef long long ll;
const ll mod=1000000007;
#define repi(i,a,b) for(ll i=ll(a);i<ll(b);++i)

int main() {
	int n;
	double d;
	cin >> n >> d;
	int cnt=0;
	for(int i=0;i<n;++i){
		double x,y;cin >>x>>y;
		double r = sqrt(x*x + y*y);
		if(r<=d) ++cnt;
	}
	cout << cnt << endl;
  return 0;
}
