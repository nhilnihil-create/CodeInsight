#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include <utility>
#include <functional>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <deque>
#include <ctime>

using namespace std;
  
#define rep(i,n) REP(i,0,n)
#define REP(i,s,e) for(int i=(s); i<(int)(e); i++)
#define pb push_back
#define mp make_pair
#define all(r) (r).begin(),(r).end()
#define rall(r) (r).rbegin(),(r).rend()
#define fi first
#define se second

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
 
const int INF = 1e9;
const ll LINF = 1e18;
const ll MOD = 1e9 + 7;
double EPS = 1e-8;
const double PI = acos(-1);

int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};

vector<int> v(4e5, 1);
vector<int> s(4e5, 0);

void f(){
	v[0]=v[1] = 0;
	for(int i = 2; i < 4e5; i++){
		if(v[i]){
			for(int j = i + i; j < 4e5; j+=i){
				v[j] = 0;
			}
		}
		s[i] = s[i-1] + v[i];
	}
}

int main(){
	f();
	int n;
	while(cin>>n && n > 0){
		cout<<s[2*n]-s[n]<<endl;
	}
}