#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < (n); i++)
#define ALL(a) (a).begin(),(a).end()
#define SORT(a) sort((a).begin(),(a).end())
#define RSORT(a) sort((a).rbegin(),(a).rend())
#define ll long long
#define pb(a) push_back(a)

#define PRINTV(v) {for(ll deB=0; deB<(v).size(); deB++){cout << (v)[deB] << " ";}cout << endl;}

int main(){
	
	
	ll X,Y;
	cin >> X >> Y;
	bool judge = false;
	REP(i, X+1){
		if(i*2+(X-i)*4==Y){
			judge = true;
			break;
		}
	}
	string s = (judge) ? "Yes" : "No";
	cout << s << endl;
	
	return 0;
}