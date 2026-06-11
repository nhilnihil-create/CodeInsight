#include<iostream>
#include<string>
#include<algorithm>
#define LL long long
#define LD long double
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

int main()
{
	FIO;
	LD a, x; cin>>a, x=a/3;
	printf("%LF", x*x*x);
}