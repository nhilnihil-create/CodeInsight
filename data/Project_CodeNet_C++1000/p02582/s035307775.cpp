#include"bits/stdc++.h"
#include<cstring>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;

int main(){
	int ans=0;
	int temp=0;
	bool before_s=false;
	string s;
	cin>>s;

	rep(i,3){
		if(before_s==false&&s[i]=='R'){
			temp=1;
		}
		else if(before_s==true&&s[i]=='R'){
			temp++;
		}
		if(ans<temp){
			ans=temp;
		}

		if(s[i]=='R'){
			before_s=true;
		}
		else if(s[i]=='S'){
			before_s=false;
		}
	}

	cout<<ans<<endl;

	return 0;
}