#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using LL = long long;
using P = pair<int,int>;


int main(){
	int A, B;
	cin >> A >> B;
	int ans = 0;
	int tmp = 1;
	while(tmp < B){
		tmp += A - 1;
		ans++;
	}
	cout << ans << endl;

}












