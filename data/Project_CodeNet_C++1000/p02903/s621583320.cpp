#include<bits/stdc++.h> 
using namespace std; 
// Binary indexed tree supporting binary search.
 
 
#define x first
#define y second
#define forn(i, n) for(int i = 0; i < int(n); ++i)
typedef pair<int, int> pii;

int H,W,A,B;
void solve(){
	cin>>H>>W>>A>>B;
	forn(i,B){
		forn(j,A){
			cout<<0;
		}
		forn(j,W-A){
			cout<<1;
		}
		cout<<'\n';
	}
	forn(i,H-B){
		forn(j,A){
			cout<<1;
		}
		forn(j,W-A){
			cout<<0;
		}
		cout<<'\n';
	}
}
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	solve();
	
	return 0;	
}