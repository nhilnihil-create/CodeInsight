//ΔAGC035C
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<bitset>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
typedef double DB;
const int N = 222222;
int n;
int main()
{
	int i,o;
	scanf("%d",&n);
	for(i=1;i<n;i<<=1);
	if(i==n){
		cout<<"No";
		return 0;
	}
	cout<<"Yes"<<endl;
	o=n;
	if(n%2==0)
		n--;
	for(i=2;i<=n;i=i+1)
		cout<<1<<' '<<i<<endl;
	for(i=2;i<=n;i=i+1)
		cout<<o+i<<' '<<(i^1)<<endl;
	cout<<o+2<<' '<<o+1<<endl;
	if(n!=o){
		n=o;
		for(i=1;i<n;i<<=1);
		i>>=1;
		cout<<n<<' '<<i<<endl;
		cout<<o+n<<' '<<(i^1^n)<<endl;
	}
	return 0;
}