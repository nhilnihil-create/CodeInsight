#include<bits/stdc++.h>
using namespace std;
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define ALL(A) A.begin(),A.end()
#define RALL(A) A.rbegin(),A.rend()
typedef long long ll;
typedef pair<ll,ll> P;
const ll mod=1000000007;
const ll LINF=1LL<<60;
const int INF=1<<30;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
	string s;cin>>s;
	ll q;cin>>q;
	deque<char> t;
	for(int i = 0; i < s.size(); i++) {
		t.push_back(s[i]);
	}
	bool reverse = false;
	for(int i = 0; i < q; i++) {
		int a;cin>>a;
		if(a == 1){
			reverse = !reverse;
		}
		else{
			int f;char c;cin>>f>>c;
			if (reverse){
				if(f == 1){
					t.push_back(c);
				}
				else{
					t.push_front(c);
				}
			}
			else{
				if(f == 1){
					t.push_front(c);
				}
				else{
					t.push_back(c);
				}
			}
		}
	}
	while(!t.empty()){
		if(reverse){
			cout << t.back();
			t.pop_back();
		}
		else{
			cout << t.front();
			t.pop_front();
		}
	}
	cout << endl;
	return 0;
}