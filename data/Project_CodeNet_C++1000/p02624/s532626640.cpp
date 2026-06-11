#include<iostream>
#include<string>
#include<algorithm>
#include<math.h>
#define LL long long
#define LD long double
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

long long d[10000001];

void f(long long n)
{
	for(long long i=1; i<=n; i++)
	{
		for(long long j=i; j<=n; j+=i) d[j]++;
	}
}

int main()
{
	FIO;
	long long n, sum=0; cin>>n, f(n);
	for(long long i=1; i<=n; i++) sum+=i*d[i];
	cout<<sum<<endl;
}