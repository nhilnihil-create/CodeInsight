#include<bits/stdc++.h>
#define randome_generate srand(std::chrono::high_resolution_clock::now().time_since_epoch().count())
using namespace std;
int m;
int d;
long long c;
long long digits,sums;
int main(){
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>m;
	for(int i=1;i<=m;i++){
		cin>>d>>c;
		digits+=c;
		sums+=d*c;
	}
	cout<<digits-1LL+(sums-1LL)/9LL<<endl;
	return 0;
}
