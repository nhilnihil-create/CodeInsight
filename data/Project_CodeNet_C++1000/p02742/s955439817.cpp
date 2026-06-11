#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	double h,w;
	cin>>h>>w;
	if(h==1 || w==1){
		cout<<1<<endl;
	}else{
		cout<<fixed<<setprecision(0)<<ceil((h*w)/2)<<endl;
	}
	return 0;
}
