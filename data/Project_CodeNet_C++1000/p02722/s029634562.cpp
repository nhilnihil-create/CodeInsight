#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <cmath>
using namespace std;
typedef long long int LL;
typedef pair<int,int> P;
const int INF=100000000;

bool hantei(LL N,LL K)
{
	if(N%K==1)return true;
	else if(N%K==0)return hantei(N/K,K);
	else return false;
}
int main(){
	LL n=0;
	LL ans=0;
	cin>>n;
	for(LL i=2;i<=sqrt(n);i++)
	{
		if(hantei(n,i))ans++;
		if((n-1)%i==0 && (n-1)/i>sqrt(n))ans++;			
	}
	if(n!=2)cout<<ans+2<<endl;
	else cout<<1<<endl;
	return 0;
}