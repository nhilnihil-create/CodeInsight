#include <iostream>
#include <algorithm>
#include <deque>
#include <string>

using namespace std;

int fr[10010];

int main(){
	
	cin.tie(0); ios_base::sync_with_stdio(0);
	long long res = 0;
	int n,p,v;
	cin>>n>>p;
	string s;
	cin>>s;
	if(p==2||p==5){
		int ac = 0;
		for(int i=n-1;i>=0;i--){
			v = s[i]-'0';
			if(v%p==0)ac++;
			res+=ac;
		}
	}
	else{
		int ba = 1;
		int ac = 0;
		fr[0]=1;
		for(int i=n-1;i>=0;i--){
			v = s[i]-'0';
			ac = (ac + v*ba)%p;
			res+=fr[ac];
			fr[ac]++;
			ba = (ba*10)%p;
		}
	}
	
	cout<<res<<endl;
	
	return 0;
}