#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n,a,b,cnt=0;
	bool f=false;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a>>b;
		if(a==b){
			cnt++;
			if(cnt>=3) f=true;
		}else{
			cnt=0;
		}
	}
	if(f){
		cout<<"Yes"<<endl;
	}else{
		cout<<"No"<<endl;
	}
	return 0;
}
