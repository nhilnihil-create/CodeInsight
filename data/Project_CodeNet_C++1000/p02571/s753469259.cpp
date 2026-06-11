#include<bits/stdc++.h>
using namespace std;

char s[10005],t[10005];
int main(int argc, char * argv[]) 
{
	cin>>s>>t;
	int lens = strlen(s);
	int lent = strlen(t);
	int ans = 10000;
	for(int i=0;(i+lent-1)<lens;i++){
		int sum = 0;
		for(int j=0;j<lent;j++)
			if(s[i+j]!=t[j]) 
				sum++;
		ans = min(ans,sum);
	}
	cout<<ans<<endl;


    return 0;
}