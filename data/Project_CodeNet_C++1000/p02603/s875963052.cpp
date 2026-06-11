// D - Road to Millionaire
#include <bits/stdc++.h>
using namespace std;
int in(){int x;cin>>x;return x;}

int main(){
	int N; cin>>N;
	int64_t yen = 1000;
	for(int nxt, now=in(), i=0; i<N-1; ++i, now=nxt)
		yen += max(0L, yen/now * ((nxt=in()) - now));
	cout<< yen <<endl;
}
