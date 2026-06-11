#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(int)(n); i++)

using namespace std;
using LL = long long;
using P = pair<int,int>;

int main(){
	int N, K;
	cin >> N >> K;
	string S;
	cin >> S;
	int dif=0;
	rep(i,N-1) if(S[i]!=S[i+1]) dif++;
	dif=max(0,dif-K*2);
	cout << N-1-dif << endl; 

	return 0;
}