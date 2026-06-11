#include<iostream>
#include<string>
#include<algorithm>
#include<math.h>
#define LL long long
#define LD long double
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

int main()
{
	FIO;
	LD a, b, x; cin>>a>>b, x=(a*b)+0.0001;
	LL i=x;
	cout<<i<<"\n";
}