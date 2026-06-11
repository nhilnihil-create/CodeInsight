#include<bits/stdc++.h>
#define mod 100000007
using namespace std;

int main()
{
int N,K,Q;scanf("%d %d %d",&N,&K,&Q);
int A[Q];for(int i=0;i<Q;i++)scanf("%d\n",&A[i]);
int scores[N];for(int i=0;i<N;i++)scores[i]=0;
for(int i=0;i<Q;i++)scores[A[i]-1]++;
for(int i=0;i<N;i++)if(scores[i]>Q-K)printf("Yes\n");else printf("No\n");
}