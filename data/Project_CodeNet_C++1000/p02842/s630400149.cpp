#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using LL = long long;
using P = pair<int,int>;

int main(){
	int N; cin >> N;
	rep(i,500009){
		int tmp;
		tmp = i * 1.08;
		if(N == tmp) {
			cout << i << endl;
			return 0;
		}
	}
	cout << ":(" << endl;

}








