#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;



int main(){
	string s;
	int q;
	cin >> s;
	cin >> q;
	
	string rhead;
	string tail;
	
	bool reversed = false;
	for ( int i = 0; i < q; i++ ){
		int type, f;
		string c;
		cin >> type;
		if ( type == 1 ){
			reversed = !reversed;
		}
		else {
			cin >> f >> c;
			if ( f == 1 && !reversed || f == 2 && reversed ){
				rhead = rhead + c;
			}
			else {
				tail = tail + c;
			}
		}
	}
	
	string head = rhead;
	reverse( head.begin(), head.end() );
	
	s = head + s + tail;
	if ( reversed )
		reverse( s.begin(),s.end() );
	
	cout << s << endl;
	
	return 0;
}

