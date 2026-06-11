
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
const ll INF=1e16;
const double EPS=1e-8;
const ll mod = 1000000007;

int64_t powm(int64_t a,int64_t b){//a^bを求める
	if(b==0){
		return 1;
	}else{
		int64_t temp = powm(a,b/2);
		temp = temp * temp;
		if(b%2==1){
			temp = temp * a;
		}
		return temp;
	}
}

int main(){
	ll n,m;
	cin>>n>>m;
	vector<vector<ll> > delay_pay;
	delay_pay.resize(110000);
	for(ll i1=0;i1<n;i1++){
		ll a,b;
		cin>>a>>b;
		delay_pay[a].push_back(b);
	}
	ll ans=0;
	priority_queue<ll> pq;
	for(ll i1=m-1;i1>=0;i1--){
		for(auto i2=delay_pay[m-i1].begin();i2!=delay_pay[m-i1].end();i2++){
			pq.push(*i2);
		}
		if(pq.empty()){
			continue;
		}
		ans += pq.top();
		pq.pop();
	}
	cout<<ans<<endl;

}
