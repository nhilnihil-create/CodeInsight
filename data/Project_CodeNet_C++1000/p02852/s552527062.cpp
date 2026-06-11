#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N, M;
string S;

int main(){
	cin >> N >> M;
	cin >> S;
	
	int pos = N;
	vector<int> steps;
	while ( pos != 0 ){
		int step = M;
		if ( pos-step < 0 )
			step = pos;
		while ( S[pos-step] == '1' )
			step--;
		if ( step == 0 ){
			cout << "-1" << endl;
			return 0;
		}
		steps.push_back(step);
		pos -= step;
	}
	
	for ( int i = steps.size()-1; i >= 0; i-- )
		cout << steps[i] << " ";
	cout << endl;
	
	return 0;
}

