#include<iostream>
#include<stack>
#include<cstring>
using namespace std;
const int M=1e9+7;
int main(){
	int l,r,d;
	cin>>l>>r>>d;
	int ans=0;
	for(int i=l;i<=r;i++){
		if(i%d==0)ans++;
	}
	cout<<ans;
	return 0;
}