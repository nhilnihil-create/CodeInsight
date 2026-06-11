#include<bits/stdc++.h>
#include<iostream>
#include<algorithm> 
#include<cstring>
using namespace std;
typedef long long ll;
const ll maxn = 1e6 + 10;
int main()
{
	int n,ans=0;
	char ch[55];
	cin>>n;
	for(int i = 1;i <= n; i++) 
		cin>>ch[i];
	for(int i = 1;i <= n;)
	{
		if(ch[i] == 'A'&& ch[i+1] == 'B'&&ch[i+2] == 'C'){
			i+=3;
			ans++;
		}
		else
			i++;
	}
	cout<<ans<<endl;
	return 0;
} 