#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


ll N;



int main(){
	cin >> N;
	ll N2 = 1LL<<N;
	vector<int> S(N2+1);
	for ( int i = 0; i < N2; i++ ){
		cin >> S[i];
	}
	S[N2] = -1;
	sort(S.begin(), S.end(), greater<int>());
	
	
	vector<int> SS;
	SS.reserve(N2+1);
	
	for ( int i = 0; i < N; i++ ){
		// [0..p-1]  と  [p..2*p-1] を比較
		int p = 1<<i;
		int k = p;
		int l = p;
		SS.resize(0);
		sort(S.begin(),S.begin()+p, greater<int>());
		
		for ( int j = 0; j < p; j++ ){
			while ( S[j] <= S[k] ){
				SS.push_back( S[k++] );
			}
			S[l++] = S[k++];
			
			if ( k > N2 ){
				cout << "No" << endl;
				
				return 0;
			}
		}
		for ( size_t j = 0; j < SS.size(); j++ ){
			S[l++] = SS[j];
		}
	}
	
	cout << "Yes" << endl;
	return 0;
}
