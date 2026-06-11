#include<bits/stdc++.h>
#include<iostream>
#include<algorithm> 
#include<cstring>
#define ios ios::sync_with_stdio(false)
#define mem(arr) memset(arr,0,sizeof(arr))
using namespace std;
typedef long long ll;
const ll maxn = 1e6 + 10;
int main()
{
	int k,x;
	cin>>k>>x;
	if(x <= k * 500)
		cout<<"Yes"<<endl;
	else
		cout<<"No"<<endl;
	return 0;	
}