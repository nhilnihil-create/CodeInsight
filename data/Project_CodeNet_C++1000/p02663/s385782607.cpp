#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using LL = long long;
using P = pair<int,int>;


int main(){
	int H1, M1, H2, M2, K;
	cin >> H1 >> M1 >> H2 >> M2 >> K;
	cout << H2*60 + M2 - (H1*60 + M1) - K << endl;
	return 0;
}







