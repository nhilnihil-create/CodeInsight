#include"bits/stdc++.h"
#include<unordered_set>
#include<unordered_map>
#include<random>
using namespace std;
typedef long long ll;
const ll MOD = 1'000'000'007LL; /*998'244'353LL;*/
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define rep(i, n) for(int (i)=0; (i)<(n); (i)++)
int dx[4]={ 1,0,-1,0 };
int dy[4]={ 0,1,0,-1 };

int N, K;
ll S;

signed main(){
	cin >> N >> K >> S;
	if(S == 1'000'000'000){
		rep(i, K) cout << S << endl;
		rep(i, N-K) cout << 1 << endl;
	}
	else{
		rep(i, K) cout << S << endl;
		rep(i, N-K) cout << 1'000'000'000 << endl;
	}
}