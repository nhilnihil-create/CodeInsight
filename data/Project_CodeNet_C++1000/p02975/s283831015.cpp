#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iostream>
#include <numeric>
#include <cstring>
#include <cassert>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <cmath>
#include <set>
#include <map>
#include <functional>
#include <bitset>

using namespace std;
#define     loop(n,i,a)     for(int i=a;i<n;i++)
#define     all(arr,n)      arr,arr+n
#define     allv(v)         (v).begin(),(v).end()
#define     rallv(v)        (v).rbegin(),(v).rend()
#define     m_p             make_pair
#define     ll              long long
#define     vi              vector<int>
#define     vll             vector<ll>
#define     sz(x)           (int)x.size()
#define     pb              push_back
int dx[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dy[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
ll Xor(ll a){
	if(a%4==0)return a;
	if(a%4==1)return 1;
	if(a%4==2)return a+1;
	else return 0;
}
int main() {
	int n;cin>>n;
	ll Xo;
	loop(n,i,0){
		int x;cin>>x;
		if(!i)Xo=x;
		else Xo^=x;
	}
	cout<<(!Xo?"Yes":"No");
}
