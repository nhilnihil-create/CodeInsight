#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using LL = long long;
using P = pair<int,int>;


int main(){
	int N;cin >> N;
	LL K; cin >> K;
	int Q;cin >> Q;
	vector<LL> p(N, K - Q);

	rep(i,Q){
		int tmp;
		cin >> tmp;
		++p[tmp-1];
	}
	rep(i,N){
		if(p[i]>0){
			cout << "Yes" << endl;
		}
		else cout << "No" << endl;
	}
}












