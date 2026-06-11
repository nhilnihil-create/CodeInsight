#include <algorithm>
#include <cmath>
#include <vector>
#include <functional>
#include <cstdlib>
#include <map>
#include <set>
#include <iostream>
#include <string>
#include <ctype.h>
#include <climits>
#include <queue>
#include <deque>
using namespace std;
#define REP(i, n) for(ll i = 0; i < (ll)(n); i++)
typedef long long ll;

int main(){
	ll q;
	string input;
	cin >> input >> q;
	deque<char> s;
	bool reverse = false;
	REP(i,input.size()){
		s.push_back(input[i]);
	}
	ll t,f;
	char c;
	REP(i,q){
		cin >> t;
		if(t==1){
			reverse = !reverse;
		}else{
			cin >> f >> c;
			if((f==2 && reverse) || (f==1 && !reverse)){
				s.push_front(c);
			}else{
				s.push_back(c);
			}
		}
	}
	
	
	REP(i,s.size()){
		if(reverse) cout << s[(ll)s.size()-1-i];
		else cout << s[i];
	}
	cout << endl;
	
	
	
	return 0;
}