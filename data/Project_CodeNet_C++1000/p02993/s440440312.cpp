#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<ll, ll> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	string s; cin >> s;
	for(int i=0;i<3;i++){
		if(s[i] == s[i+1]){
			cout << "Bad" << endl;
			return 0;
		}
	}
	cout << "Good" << endl;
}
