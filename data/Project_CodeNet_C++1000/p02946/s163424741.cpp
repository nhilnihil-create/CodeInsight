#include<iostream>
#include<math.h>
#include<algorithm>
#define LL long long
#define FIO ios_base::sync_with_stdio(false), cin.tie(0)
using namespace std;

int main()
{
	int k, x, st, end; cin>>k>>x;
	st=max(-1000000, x-k+1), end=min(1000000, x+k-1);
	for(int i=st; i<=end; i++) cout<<i<<" ";
	cout<<endl;
}