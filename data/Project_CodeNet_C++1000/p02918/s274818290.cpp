#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


ll N, K;



int main(){
	cin >> N >> K;
	string S;
	cin >> S;
	
	// 幸福の最大値はN-1
	// 不連続点1つごとに 幸福-1
	int happy = N-1;
	for ( int i = 1; i < N; i++ ){
		if ( S[i] != S[i-1] )
			happy--;
	}
	
	// 操作1回ごとに、不連続点が2点解消る
	happy += K*2;
	if ( happy > N-1 )
		happy = N-1;
	
	cout << happy << endl;
	return 0;
}
