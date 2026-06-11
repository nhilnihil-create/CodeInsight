
#include <time.h>

#include <stdlib.h>
#include <cstdint>
#include <cassert>
#include <algorithm>
#include <functional>
#include <iostream>
#include <limits>
#include <cstdint>
#include <cassert>
#include <algorithm>
#include <functional>
#include <iostream>
#include <limits>
#include <vector>
#include <map>
#include <set>
#include <iomanip>
#include <numeric>
#include <cmath>
#include <bitset>
#include <iterator>
#include <deque>
#include <string>
#include <queue>
#include <omp.h>
#include <fstream>   // ifstream, ofstream
typedef int64_t ll;
using namespace std;
const ll INF=1e10;
const double EPS=1e-8;
const ll mod = 1000000007;
int main(){
	ll n,k;
	cin>>n>>k;
	vector<vector<ll> > edges;
	edges.resize(n);
	for(ll i1=0;i1<n-1;i1++){
		ll a,b;
		cin>>a>>b;
		edges[a-1].push_back(b-1);
		edges[b-1].push_back(a-1);
	}
	if(n==1){
		cout<<k<<endl;
	}else{
		ll ans = (k*(k-1))%mod;
		for(ll i1=0;i1<n;i1++){
			for(ll i2=0;i2<edges[i1].size()-1;i2++){
				ans *= (k-2-i2);
				ans %= mod;
				if(ans==0){
					cout<<0<<endl;
					return 0;
				}
			}
		}
		cout<<ans<<endl;
	}

}
