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
//#define mod 998244353
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
const int SIZE=550;
//↑templete
int main() {
	int N;
	cin>>N;
	int D[SIZE][SIZE]={};
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			for(int k=0;k<32;k++)
				if(((i>>k)&1)^((j>>k)&1)){
					D[i][j]=k+1;
					break;
				}
	for(int i=0;i<N;i++){
		for(int j=i+1;j<N;j++)
			cout<<D[i][j]<<" ";
		cout<<endl;
	}
	return 0;
}