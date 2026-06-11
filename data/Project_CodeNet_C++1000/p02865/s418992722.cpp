#include <bits/stdc++.h>

using namespace std;
using ll =long long;
using db = double;
using vll = vector<long long>;

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
#define che(a,string) cout<<"//"<<string <<"=="<<(a)<<"//" <<endl;
#define SORT(a) sort((a).begin(),(a).end())
#define rSORT(a) reverse((a).begin(),(a).end())
#define For(i, a, b)    for(int i = (a) ; i < (b) ; ++i)
#define rep(i, n)       For(i, 0, n)
#define leftunique(a) {SORT(a);(a).erase(unique((a).begin(),(a).end()),(a).end());}
//leftuniqueは配列から同じ要素のものを取り除く 例 4 6 2 1 3 4 1 2 なら 1 2 3 4 6 になる
#define debug(x)  cout << #x << " = " << (x) << endl;
bool IsInt(double a){int b = a/1;if(a==b){return true;}else {return false;}}
bool coY() {cout <<"Yes"<<endl;}
bool coN(){cout <<"No"<<endl;}
const int mod = 1e9 + 7;
const ll INF = 1LL << 60;
//ここから書き始める

int main()
{
	cout <<setprecision(10);
	int n ; cin >> n;
	if(n % 2 == 1){
		n ++ ;
	}
	cout << (n)/2 - 1 << endl;
}
