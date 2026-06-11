
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


string S, T;

int main(){
	cin >> S >> T;
	int len = S.length();
	
	string SS = S + S;
	
	vector<bool> valid_char(26);
	vector<int> addpos[26];  // 現在位置posで次の文字がcの場合、次の位置は pos+addpos[c][pos]
	
	for ( int c = 0; c < 26; c++ ){
		addpos[c].resize(len);
		int lastpos = 0;
		for ( int i = 0; i < len*2; i++ ){
			if ( SS[i]-'a' == c ){
				valid_char[c] = true;
				
				for ( int j = lastpos; j < i; j++ ){
					addpos[c][j%len] = (i-j+(len-1))%len+1;
				}
				lastpos = i;
				if ( i >= len )
					break;
			}
		}
		//if ( valid_char[c] ){
		//	cout << c << endl;
		//	for ( auto it : addpos[c] )
		//		cout << it << " ";
		//	cout << endl;
		//}
	}
	
	ll ct = -1;
	ll pos = len-1;
	
	for ( size_t j = 0; j < T.length(); j++ ){
		int c = T[j]-'a';
		if ( valid_char[c] ){
			pos += addpos[c][pos];
			if ( pos >= len ){
				pos -= len;
				ct++;
			}
		}
		else {
			cout << "-1" << endl;
			return 0;
		}
	}
	

	cout << (ct*len+pos+1) << endl;
	
	return 0;
}

