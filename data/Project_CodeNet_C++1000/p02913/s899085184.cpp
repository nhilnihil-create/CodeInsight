#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <cmath>
#include <bitset>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>
#include <complex>
#include <unordered_map>
#include <unordered_set>
#include <random>
#include <cassert>
#include <fstream>
#include <utility>
#include <functional>
#include <time.h>
#include <stack>
#include <array>
#define popcount __builtin_popcount
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<ll mod>
struct RollingHash{
	vector<ll> hash, power;

	RollingHash(const string &s, ll base=10007){
		int sz=s.size();
		hash.resize(sz+1);
		power.resize(sz+1);
		power[0]=1;
		for(int i=0; i<sz; i++){
			power[i+1]=power[i]*base%mod;
			hash[i+1]=(hash[i]*base+s[i])%mod;
		}
	}

	ll get(int l, int r) const{ // [l, r)
		ll ret=hash[r]-hash[l]*power[r-l]%mod+mod;
		if(ret>=mod) ret-=mod;
		return ret;
	}

	ll concat(ll h1, ll h2, int len2) const{ //h1+h2
		ll ret=h1*power[len2]%mod+h2;
		if(ret>=mod) ret-=mod;
		return ret;
	}
};
int main()
{
	int n; cin>>n;
	string s; cin>>s;
	const ll MOD1=1e9+7;
	const ll MOD2=1e9+9;
	RollingHash<MOD1> rh1(s);
	RollingHash<MOD2> rh2(s);
	int ans=0;
	for(int i=0; i<n; i++){
		for(int j=i+1; j<n; j++){
			while(i+ans<j && j+ans<n){
				ll h1=rh1.get(i, i+ans+1)-rh1.get(j, j+ans+1), h2=rh2.get(i, i+ans+1)-rh2.get(j, j+ans+1);
				if(h1!=0 || h2!=0) break;
				ans++;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
