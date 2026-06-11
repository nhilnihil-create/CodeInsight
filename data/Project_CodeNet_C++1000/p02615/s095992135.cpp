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
long long n,a[K],ans;
priority_queue<int> pq;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	pq.push(a[n]);
	for(int i=n-1;i>=1;i--)
	{
		ans+=pq.top();
		pq.pop();
		pq.push(a[i]);
		pq.push(a[i]);
	}
	cout<<ans;
	return 0;
}