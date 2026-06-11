#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<climits>
#include<iostream>
#include<sstream>
#include<utility>
#include<map>
#include<vector>
#include<queue>
#include<algorithm>
#include<set>
#include<stack>
using namespace std;
typedef long long ll;
typedef pair<int,int>P;
struct X{int P,K,D;vector<int>C;}A[100005];
int N;
 
int main()
{
	scanf("%d",&N);
	for(int i=0;i<N;i++)A[i].P=-1;
	for(int i=0;i<N;i++)
	{
		int n;
		scanf("%d",&n);
		scanf("%d",&A[n].K);
		for(int j=0;j<A[n].K;j++)
		{
			int t;
			scanf("%d",&t);
			A[t].P=n;
			A[n].C.push_back(t);
		}
	}
	for(int i=0;i<21;i++)
	{
		for(int j=0;j<N;j++)
			if(A[j].P!=-1)
				A[j].D=A[A[j].P].D+1;
	}
	for(int i=0;i<N;i++)
	{
		printf("node %d: parent = %d, depth = %d, %s, [",i,A[i].P,A[i].D,A[i].P==-1?"root":A[i].K==0?"leaf":"internal node");
		for(int j=0;j<A[i].K;j++)
			printf("%d%s",A[i].C[j],j==A[i].K-1?"":", ");
		puts("]");
	}
	return 0;
}