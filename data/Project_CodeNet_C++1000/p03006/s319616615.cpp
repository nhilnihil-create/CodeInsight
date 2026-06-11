#include <bits/stdc++.h>

using namespace std;
using ll =long long;

#define SORT(a) sort((a).begin(),(a).end())
#define rSORT(a) reverse((a).begin(),(a).end())
#define For(i, a, b)    for(int i = (a) ; i < (b) ; ++i)
#define rep(i, n)       For(i, 0, n)
#define debug(x)  cerr << #x << " = " << (x) << endl;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
bool coY() {cout <<"Yes"<<endl;}
bool coN(){cout <<"No"<<endl;}

const ll INF = 1LL << 60;

ll n,m;
string s;
//Write From this Line

const int mod = 1e9+7;
int main()
{
	cin >> n ;
	vector<pair<int,int>> P(n);
	rep(i,n){
		cin >>P[i].first>>P[i].second; 
	}
	SORT(P);
	
	map<pair<int,int>,int> kasa;
	int ans =  n; 
	int M = 0 ;
	for(int i = 0 ; i < n ;  i ++ ) {
		for ( int  j = i + 1 ; j < n ; j ++){
			int x = P[j].first - P[i].first ;
			int y = P[j].second - P[i].second; 
			pair<int,int> xy = make_pair(x,y);
			kasa[xy] ++;
			chmax(M,kasa[xy]);
		}
	}
	cout << ans-M << endl;

}
