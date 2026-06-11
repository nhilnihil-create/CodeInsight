#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
#include <utility>
#include <cmath>
using namespace std;
using ll=long long;
using P=pair<int,int>;
#define rep(i,a,b) for(ll i=a;i<ll(b);i++)
#define repr(i,a,b) for(ll i=a;i>=ll(b);i--)
#define endl '\n'
#define ALL(x) x.begin(),x.end()
#define ALLR(x) x.rbegin(),x.rend()
#define INF 1e9
#define DEBUG(x) cout<<"debug: "<<x<<endl
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}return 0;}
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return 0;}

string s;
int main(){
	cin >> s;
	int N = s.length();
	string a = s.substr(0,  (N-1)/2);
	string b = s. substr( ((N+3)/2)-1 );
	
	if(s == string(ALLR(s))){
	if(a == string(ALLR(a))){	
	if(b == string(ALLR(b))){
		cout << "Yes" << endl;
		return 0;
	}}}
	cout << "No" << endl;
    return 0;
}
