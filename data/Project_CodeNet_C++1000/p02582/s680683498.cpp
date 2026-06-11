#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,x,y) for(ll i=x;i<=y;i++)
#define imin INT_MIN
#define imax INT_MAX
int mod =1e9+7;

int main(){
	cin.tie(NULL);
    ios_base::sync_with_stdio();

	string s;
	cin>>s;
	int n = s.size();
	int cnt=0,dcnt=0;
	for(int i=0; i<n; i++){
		if(s[i]=='R'){
			cnt++;
		}
	}
	if(cnt==3){
		cout<<3<<"\n";
	}else if(cnt==2){
		if(s[1]=='S'){
			cout<<1<<"\n";
		}else{
			cout<<2<<"\n";
		}
	}else if(cnt==1){
		cout<<1<<"\n";
	}else if(cnt==0){
		cout<<cnt<<"\n";
	}
	
	return 0;
}