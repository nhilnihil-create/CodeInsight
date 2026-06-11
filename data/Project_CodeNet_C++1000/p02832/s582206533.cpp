#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i < (n); i++)
using namespace std;
using ll = long long;

int main(){
	ios::sync_with_stdio(false);

	int N; cin>>N;
	vector<int> a(N);
	rep(i,N) cin>>a[i];

	int now=1, count=0;
	for(int i=0; i<N; i++){
		if(a[i]==now){
			now++;
		}else{
			count++;
		}
	}

	if(count==N){
		cout << -1 << endl;
	}else{
		cout << count << endl;
	}
}
