#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e9;
signed main(){
	int S;cin>>S;
	cout<<0<<" "<<0<<endl;
	cout<<N<<" "<<1<<endl;
	int y3=S/N+bool(S%N);
	cout<<N*y3-S<<" "<<y3<<endl;
	return 0;
}