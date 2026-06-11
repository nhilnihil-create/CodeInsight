#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1000000001
#define INFL 1000000000000000001
string s;
int ans=1;
int main(void){
	cin>>s;
	int n=s.size();
	int p=0;
	while(p<n-1){
		if(s[p]!=s[p+1])p++,ans++;
		else{
			if(p+1==n-1)p++;
			else if(p+1==n-2)p+=2,ans++;
			else p+=3,ans+=2;
		}
	}
	cout<<ans<<endl;
}
