/***** Raf *****/
///#include <stdio.h>
///#include <iostream>
///#include <cstring>
///#include <cmath>
///#include <algorithm>
///#include <string>
///#include <vector>
///#include <map>
///#include <set>
///#include <queue>
///#include <cstdlib>
///#include <limits>
///#include <iostream>
///#include <sstream>
///#include <unordered_set>
///#include <unordered_map>
///#include <random>
#include <bits/stdc++.h>
///#include <bits/stdtr1c++.h>
///#include <ext/pb_ds/assoc_container.hpp>
///#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
///using namespace __gnu_pbds;

#define              MAX             500005
#define              EPS             1e-9
#define              ull             unsigned long long
#define              ll              long long
#define              inf             INT_MAX
#define              pi              acos(-1.0)
#define              vi              vector<int>
#define              vl              vector<long long>
#define              pii             pair<int,int>
#define              pll             pair<long long,long long>
#define              mp              make_pair
#define              mem(a, v)       memset(a, v, sizeof (a))
#define              mod             1000000007
#define              all(a)          a.begin(),a.end()
#define              rall(a)         a.rbegin(),a.rend()
#define              ff              first
#define              ss              second
#define              arsort(ar,n)    sort(ar,ar+n);
#define              vsort(v)        sort(v.begin(),v.end())
#define              vrev(v)         reverse(v.begin(),v.end())
#define              arrev(ar,n)     reverse(ar,ar+n)
#define              pb              push_back
#define              popb            pop_back
#define              booster()       ios_base::sync_with_stdio(0); cin.tie(0);
#define              read(f)         freopen(f, "r", stdin)
#define              write(f)         freopen(f, "w", stdout)
#define              scani(x)        scanf("%d",&x)
#define              scanl(x)        scanf("%I64d",&x)
#define              scand(x)        scanf("%lf",&x)
#define              scans(x)        scanf("%s",x)
#define              OUT(x)          printf("%d\n",x)
#define              OUTS(x)         printf("%d ",x)
#define              min3(a,b,c)     min(a,min(b,c))
#define              max3(a,b,c)     max(a,max(b,c))
#define              min4(a,b,c,d)   min(min(a,b),min(c,d))
#define              max4(a,b,c,d)   max(max(a,b),max(c,d))
#define              max5(a,b,c,d,e) max(max3(a,b,c),max(d,e))
#define              min5(a,b,c,d,e) min(min3(a,b,c),min(d,e))

#define              bitCheck(a,k)     ((bool)(a&(1<<(k))))
#define              bitOff(a,k)       (a&(~(1<<(k))))
#define              bitOn(a,k)        (a|(1<<(k)))
#define              bitFlip(a,k)      (a^(1<<(k)))

#define              POPCOUNT           __builtin_popcount
#define              POPCOUNTLL         __builtin_popcountll
#define              RIGHttmOST          __builtin_ctzll
#define              LEFttmOST(x)        (63-__builtin_clzll((x)))

#define scani2(a,b) scani(a) , scani(b)
#define scani3(a,b,c) scani(a), scani(b), scani(c)
#define scani4(a,b,c,d) scani(a), scani(b), scani(c), scani(d)
#define scani5(a,b,c,d,e) scani(a), scani(b), scani(c), scani(d) , scani(e)
#define rnd mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

/*********************Ordered Multiset*************************/

/*** Needs C++11 or C++14 ***/
/// Treap supporting duplicating values in set
/// Maximum value of treap * ADD must fit in long long

/*

struct Treap{ /// hash = 96814
	int len;
	const int ADD = 1000010;
	const int MAXVAL = 1000000010;
	tr1::unordered_map <long long, int> mp; /// Change to int if only int in treap
	tree<long long, null_type, less<long long>, rb_tree_tag, tree_order_statistics_node_update> T;
	Treap(){
		len = 0;
		T.clear(), mp.clear();
	}
	inline void clear(){
		len = 0;
		T.clear(), mp.clear();
	}
	inline void insert(long long x){
		len++, x += MAXVAL;
		int c = mp[x]++;
		T.insert((x * ADD) + c);
	}
	inline void erase(long long x){
		x += MAXVAL;
		int c = mp[x];
		if (c){
			c--, mp[x]--, len--;
			T.erase((x * ADD) + c);
		}
	}
	/// 1-based index, returns the K'th element in the treap, -1 if none exists
	inline long long kth(int k){
		if (k < 1 || k > len) return -1;
		auto it = T.find_by_order(--k);
		return ((*it) / ADD) - MAXVAL;
	}
	/// Count of value < x in treap
	inline int count(long long x){
		x += MAXVAL;
		int c = mp[--x];
		return (T.order_of_key((x * ADD) + c));
	}
	/// Number of elements in treap
	inline int size(){
		return len;
	}
};

typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;///*X.find_by_order();X.order_of_key();
template <class T> inline bool isLeap(T y) {return (y % 400 == 0) || (y % 100 ? y % 4 == 0 : false); }*/
template< class T > inline T gcd(T a, T b) { return (b) == 0 ? (a) : gcd((b), ((a) % (b))); }
template< class T > inline T lcm(T a, T b) { return ((a) / gcd((a), (b)) * (b)); }
template <class T> inline T BigMod(T Base,T power,T M=mod){if(power==0)return 1;if(power&1)return ((Base%M)*(BigMod(Base,power-1,M)%M))%M;
else{T y=BigMod(Base,power/2,M)%M;return (y*y)%M;}}
template <class T> inline T ModInv (T A,T M = mod){return BigMod(A,M-2,M);}

int fx[] = {-1,+0,+1,+0,+1,+1,-1,-1,+0};
int fy[] = {+0,-1,+0,+1,+1,-1,+1,-1,+0};
int day[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

/*********************** let the play begin() ***********************************/

int main()
{
	booster()
	//read("input.txt");
	string s;
	cin >> s;
	int len = s.size();
	vi ri(len,-1),le(len,-1);
	for(int i = 0;i<len;i++){
		if(s[i]=='L') continue;
		int indx = i;
		while(i+1<len&&s[i+1]==s[i]) i ++;
		if(i+1<len) {
			for(int j = indx;j<=i;j++) ri[j] = i + 1;
		}
	}
	for(int i = len-1;i>=0;i--){
		if(s[i]=='R') continue;
		int indx = i;
		while(i-1>=0&&s[i-1]==s[i]) i --;
		if(i-1>=0) {
			for(int j = indx;j>=i;j--) le[j] = i-1;
		}
	}

	vi ans(len);

	for(int i = 0;i<len;i++){
		if(s[i]=='L'){
			if(le[i]==-1) ans[0] ++;
			else {
				int x = i - le[i];
				if(x&1) ans[le[i]+1] ++;
				else ans[le[i]] ++;
			}
		}
		else {
			if(ri[i]==-1) ans[len-1] ++;
			else {
				int x = ri[i] - i;
				if(x&1) ans[ri[i]-1] ++;
				else ans[ri[i]] ++;
			}
		}
	}

	for(int i = 0;i<len;i++){
		cout << ans[i] << " ";
	}

	return 0;
}
