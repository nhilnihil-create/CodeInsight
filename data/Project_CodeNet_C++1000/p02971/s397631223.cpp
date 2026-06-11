#include <bits/stdc++.h>

using namespace std;
using ll =long long;
typedef pair<int,int> P;
#define SORT(a) sort((a).begin(),(a).end())
#define REV(a) reverse((a).begin(),(a).end())
#define For(i, a, b)    for(int i = (a) ; i < (b) ; ++i)
#define rep(i, n)       For(i, 0, n)
#define debug(x)  cerr << #x << " = " << (x) << endl;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

void coY() {cout <<"Yes"<<endl;}
void coN(){cout <<"No"<<endl;}
 
//Write From this Line

//const ll mod = 1e9+7;
//const ll mod = 998244353;
int main()
{
	int n;
	cin >> n;
	vector<int> a(n);
	vector<int> b(n);
	rep(i, n){
		cin>>a[i];
		b[i] = a[i];
	}
	SORT(b);
	REV(b);
	bool usi = true;
	if(b[0] != b[1]){
		usi = false;
	}
	rep(i,n){
		if(usi){
			cout << b[0] << endl;
		} else {
			if(a[i] == b[0]){
				cout << b[1] << endl;
			} else {
				cout << b[0] << endl;
			}
		}
	}

}
