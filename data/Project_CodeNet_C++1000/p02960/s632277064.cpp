#include <bits/stdc++.h>
using namespace std;
typedef long long ll;



int q_num = 0; // ? の数
int p10[100001]; // p10[i] = 10^(1+i番目の?の位置)
ll ct[100001][13] = {0}; // ct[i][j] = ?を1+i番目まで確定した場合に余りがjになる個数 


int main(){
	string S;
	cin >> S;
	int len = S.length();
	
	int remain0 = 0; // ?の文字が全て0とした場合の、S % 13
	int p = 1; // 10^(len-i-1) % 13
	for ( int i = 0; i < len; i++ ){
		int j = len - 1 - i;
		if ( S[j] == '?' ){
			p10[q_num] = p;
			q_num++;
		}
		else {
			remain0 = (remain0 + (S[j]-'0')*p) % 13;
		}
		p = p * 10 % 13;
	}
	
	
	ct[0][remain0] = 1;
	
	for ( int i = 0; i < q_num; i++ ){
		for ( int j = 0; j < 13; j++ ){
			for ( int k = 0; k < 10; k++ ){
				ct[i+1][(p10[i]*k+j)%13] += ct[i][j];
			}
		}
		for ( int j = 0; j < 13; j++ )
			ct[i+1][j] %= 1000000007;
	}
	
//	for ( int i = 0; i < q_num+1; i++ ){
//		for ( int j = 0; j < 13; j++ )
//			cout << ct[i][j] << " ";
//		cout << endl;
//	}
	
	
	cout << ct[q_num][5] << endl;
	
	return 0;
}

