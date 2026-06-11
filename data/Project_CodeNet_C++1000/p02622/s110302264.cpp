#include <bits/stdc++.h>

#define mp make_pair
#define ff first
#define ss second
#define pii pair <int,int>
#define pb push_back
#define debug(x)  cerr << #x << " = " << x << endl
using namespace std ;
typedef long long ll ;


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string s,t ;
	int x=0 ;
	cin >> s >> t ;
	for(int i =0 ; i<s.size() ; i++){
		if(s[i] != t[i]){
			x++ ;
		}
	}
	cout << x ;
	return 0 ;
}
