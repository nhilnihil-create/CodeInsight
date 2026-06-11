/* 競プロ用のテンプレ
 * SKMT
 * 作成日   2020年09月06日  16:06
 * ファイル名    bishop.cpp
 * 解けなかった...
 */
#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < n; i++)

int main(int argc, char const* argv[]){
	long long H,W; //表現できる値が10^9くらいでも大丈夫?
	long long res;
	cin>>H>>W;
	if(H==1 || W==1){
		cout << 1 << endl;
		res=1;
	}
	else {
		res=(H*W+1)/2;
		cout << (H*W +1)/2 << endl;
	}
	return 0;
}
