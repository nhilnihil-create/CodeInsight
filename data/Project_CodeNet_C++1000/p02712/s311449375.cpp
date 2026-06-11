#include<iostream>
#include<string>
#include<algorithm>
#define LL long long
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

int main()
{
	FIO;
	LL n, sum=0; cin>>n;
	for(LL i=1; i<=n; i++) if(i%3!=0&&i%5!=0) sum+=i;
	cout<<sum<<endl;
}