#include <bits/stdc++.h>

using namespace std;
typedef long long ll;


ll N;


int main(){
	cin >> N;
	string S;
	cin >> S;
	S += " ";
	S[N] = ' ';
	
	int max_match_len = 0;
	for ( int dist = 1; dist <= N-1; dist++ ){
		int match_len = 0;
		for ( int i = 0; i < N-dist+1; i++ ){ // 最後に必ずelse側を実行するよう+1する
			if ( S[i] == S[i+dist] ){
				match_len++;
			}
			else {
				int valid_match_len = min( dist, match_len );
				max_match_len = max( max_match_len, valid_match_len );
				if ( valid_match_len == dist )
					break;
				match_len = 0;
			}
		}
		
	}
	
	cout << max_match_len << endl;


	return 0;
}
