#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define mod 1000000007
#define exp pow(10,-9)
#define F first
#define S second
#define PB push_back 
#define MP make_pair
#define daman ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define lowercase(str) transform(str.begin(), str.end(), str.begin(), ::tolower);
#define uppercase(str) transform(str.begin(), str.end(), str.begin(), ::toupper);
main(){
	int n;
	cin>>n;
	int numb,count = 0;
	
	for(int i=1;i<=n;i++)
	{
		cin>>numb;
		if(i%2==1 && numb%2 == 1)
			count++;
	}
	cout<<count<<"\n";
}