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
struct RollingHash{
	using ull=unsigned long long;
	const ull mask30=(1ll<<30)-1;
	const ull mask31=(1ll<<31)-1;
	const ull mod=(1ll<<61)-1;
	const ull positivizer=(mod<<2);

	ull calcmod(ull x){
		ull ret=(x>>61)+(x&mod);
		if(ret>=mod) ret-=mod;
		return ret;
	}
	ull mul(ull a, ull b){
		ull au=(a>>31), ad=(a&mask31), bu=(b>>31), bd=(b&mask31);
		ull mid=au*bd+ad*bu;
		ull midu=(mid>>30), midd=(mid&mask30);
		ull ret=((au*bu)<<1)+midu+(midd<<31)+ad*bd; //ret<2^63
		/*ret=(ret>>61)+(ret&mod);
		if(ret>=mod) ret-=mod;*/
		return ret;
	}

	vector<ull> hash, power;

	RollingHash(const string &s, ull base=1000000007){
		int sz=s.size();
		hash.resize(sz+1);
		power.resize(sz+1);
		power[0]=1;
		for(int i=0; i<sz; i++){
			power[i+1]=calcmod(mul(power[i], base));
			hash[i+1]=calcmod(mul(hash[i], base)+s[i]);
		}
	}

	ull get(int l, int r){ // [l, r)
		return calcmod(hash[r]+positivizer-mul(hash[l], power[r-l]));
	}

	ull concat(ll h1, ll h2, int len2){ //h1+h2
		return calcmod(mul(h1, power[len2])+h2);
	}
};
int main()
{
	int n; cin>>n;
	string s; cin>>s;
	RollingHash rh(s);
	int ans=0;
	for(int i=0; i<n; i++){
		for(int j=i+1; j<n; j++){
			while(i+ans<j && j+ans<n){
				if(rh.get(i, i+ans+1)!=rh.get(j, j+ans+1)) break;
				ans++;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
