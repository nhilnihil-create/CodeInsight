#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <unordered_map>
#include <functional>
#include <utility>
#include <tuple>
#include <cctype>
#include <bitset>
#include <complex>
#include <cmath>
#include <array>
#include <numeric>
using namespace std;
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL
//#define MOD 998244353
#define MOD 1000000007
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define eb emplace_back
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pint;
typedef pair<ll,ll> pll;
typedef tuple<int,int,int> tint;
typedef vector<int> vint;
typedef vector<ll> vll;
typedef vector<ull> vull;
typedef vector<pint> vpint;
int dx[8]={0,0,-1,1,1,1,-1,-1};
int dy[8]={-1,1,0,0,1,-1,1,-1};
const int SIZE=100050;
//↑templete
signed main(){

	int K, Q;
	cin>>K>>Q;
	vll D;
	ll Dsum=0;
	for(int i=0;i<K;i++){
		int d;
		cin>>d;
		D.pb(d);
		Dsum+=d;
	}
	while(Q--){
		ll N, X, M;
		cin>>N>>X>>M;

		vint E;
		ll Esum=0, L=0;
		for(int i=0;i<K;i++){
			E.pb(D[i]%M);
			Esum+=E.back();
			if(E.back()==0)
				L++;
		}

		//Aがmod Mで何回転するか？
		ll sum=X%M;
		sum+=Esum*((N-1)/K);
		//cout<<sum<<endl;
		ll equal=L*((N-1)/K);
		for(int i=0;i<(N-1)%K;i++){
			sum+=E[i];
			if(E[i]==0)
				equal++;
		}
		//cout<<sum<<endl;
		
		ll rou=sum/M;
		cout<<N-1-rou-equal<<endl;


	}

	return 0;
}