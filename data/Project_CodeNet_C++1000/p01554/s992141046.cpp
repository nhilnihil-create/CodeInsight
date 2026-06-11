#include <iostream>
#include <algorithm>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

int main(){
	int n; cin>>n;
	string s[n]; rep(i,n) cin>>s[i];
	int m; cin>>m;
	int cnt=0;
	rep(i,m){
		string t; cin>>t;
		bool flg=0;
		rep(j,n){
			if(t==s[j]) flg=1;
		}
		if(flg){
			cnt++;
			if(cnt%2==1) cout<<"Opened by "<<t<<endl;
			else cout<<"Closed by "<<t<<endl;
		}else{
			cout<<"Unknown "<<t<<endl;
		}
	}
	return 0;
}

