#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<utility>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<functional>
#include<math.h>
#include<random>
#include <bitset>
#include <deque>
using namespace std;
#define N (1000000000+7)
//#define N 998244353
#define INF 1e16
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> Q;
typedef vector<ll> vec;
typedef vector<vec> mat;
const int inf = (int)1e9; 
 
ll gcd(ll a, ll b) {
	if (b > a) {
		ll tmp = b;
		b = a;
		a = tmp;
	}
	if (a%b == 0)return b;
	else return gcd(b, a%b);
}

int doubling[64][200010];

int main(void){
	int n;
	ll k;
	cin>>n>>k;
	for(int i=0;i<n;i++){
		int a;
		cin>>a;
		doubling[0][i+1] = a;
	}
	for(int k=0;k<60;k++){
		for(int i=1;i<=n;i++){
			doubling[k+1][i] = doubling[k][doubling[k][i]];
		}
	}
	int now = 1;
	for(ll i=60;i>=0;i--){
		if((k>>i)&1){
			now = doubling[i][now];
		}
	}
	cout<<now<<endl;
	return 0;
}