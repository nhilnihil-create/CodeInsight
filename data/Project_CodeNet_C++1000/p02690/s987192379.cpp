#include<functional>
#include<algorithm>
#include<iostream>
#include<iomanip>
#include<cstring>
#include<cstdlib>
#include<utility>
#include<string>
#include<cstdio>
#include<vector>
#include<bitset>
#include<cmath>
#include<ctime>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
using namespace std;
const int inf=2147483647,dx[]={-1,0,1,0},dy[]={0,-1,0,1};// 上 左 下 右
const int N=100005,M=1000005,K=200005,mod=1000000007;
const long long llinf=9223372036854775807ll;
//int & long long
long long x,a,b;
int main(){
	cin>>x;
	for(a=0;a<=10000;a++)
		for(b=0;b<=10000;b++)
		{
			int A=a*a*a*a*a,B=b*b*b*b*b;
			if(A-B==x)
			{
				cout<<a<<' '<<b;
				return 0;
			}
			if(A+B==x)
			{
				cout<<a<<" -"<<b;
				return 0;
			}
		}
	return 0;
}