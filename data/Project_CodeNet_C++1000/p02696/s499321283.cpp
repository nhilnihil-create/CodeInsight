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
double A,B,n;
int main(){
	cin>>A>>B>>n;
	if(n<B)
		cout<<floor((n/B)*A);
	else
		cout<<floor(((B-1.0)/B)*A);
	return 0;
}