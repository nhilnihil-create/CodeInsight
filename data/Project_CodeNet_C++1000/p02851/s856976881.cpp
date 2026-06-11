#include <cassert>
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cwchar>
#include <cwctype>
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#include <array>
#include <atomic>
#include <chrono>
#include <codecvt>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rep2(i, n) for(int i = 1; i <= (int)(n); i++)
#define all(x) (x).begin(),(x).end()
using namespace std;
typedef int64_t ll;
typedef long double ld;
const ll INF=(1LL<<62);
const double inf=pow(10,10);
const ld pi=acosl(1);
const ll mod = 1000000007;
const int dx[4]={0,1,0,-1};
const int dy[4]={1,0,-1,0};
const int ddx[8]={1,0,-1,-1,-1,0,1,1};
const int ddy[8]={1,1,1,0,-1,-1,-1,0};

int main(){
	ll N,K;cin>>N>>K;
	vector<ll>A(N);
	rep(i,N){
		cin>>A[i];
		A[i]--;
	}
	vector<ll>sum(N+1,0);
	map<ll,ll>mp;
	
	rep(i,N){
		sum[i+1]=sum[i]+A[i];
		sum[i+1]%=K;
	}
	ll ans=0;
	rep(i,N+1){
		if(i-K>=0)mp[sum[i-K]]--;
		ans+=mp[sum[i]];
		mp[sum[i]]++;
	}
	
	cout<<ans<<endl;
}
