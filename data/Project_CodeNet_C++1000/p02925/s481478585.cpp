#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


ll N;

vector<ll> A[1000]; // Aij


int main(){
	cin >> N;
	
	for ( int i = 0; i < N; i++ ){
		A[i].resize(N-1);
		for ( int j = N-2; j >= 0; j-- ){
			cin >> A[i][j];
			A[i][j]--;
		}
	}
	
	int day = 0;
	set<int> need_test;
	for ( int i = 0; i < N; i++ )
		need_test.insert(i);
	
	while ( true ){
		set<int> s;
		
		for ( auto i: need_test ){
			if ( !A[i].empty() ){
				int j = A[i].back();
				if ( !A[j].empty() && A[j].back() == i ){
					s.insert(i);
					s.insert(j);
				}
			}
		}
		need_test.clear();
		
		if ( s.empty() )
			break;
		for ( auto it : s ){
			//cout << day << ":" << A[it].back() << endl;
			A[it].pop_back();
			need_test.insert(it);
		}
		day++;
	}
	
	bool remain = false;
	for ( int i = 0; i < N; i++ ){
		if ( A[i].size() != 0 )
			remain = true;
	}
	
	if ( remain )
		cout << "-1" << endl;
	else
		cout << day << endl;
	
	return 0;
}
