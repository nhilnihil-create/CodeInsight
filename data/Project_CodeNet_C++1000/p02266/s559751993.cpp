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
typedef struct D{int h,p;long long s;}D;

#define ML 20005
char S[ML];
int i,A,nh=0,np,k,mh=0;
long long R[ML],r=0;
stack<D>ST;
int main()
{
	gets(S);
	for(i=np=0;S[i];i++)
	{
		if(S[i]=='\\')
		{
			D tmp={nh--,i,0};
			mh=max(mh,tmp.h);
			ST.push(tmp);
		}
		else if(S[i]=='/')
		{
			int ts=0;
			nh++;
			if(nh>mh)continue;
			for(;!ST.empty()&&ST.top().h<nh;)
			{
				ts+=ST.top().s;
				ST.pop();
			}
			if(!ST.empty()&&ST.top().h==nh)
			{
				D tmp=ST.top();ST.pop();
				tmp.s+=ts+i-tmp.p;
				ST.push(tmp);
			}
		}
	}
	for(i=ST.size(),k=0;i>0;i--)
	{
		if(ST.top().s)
		{
			r+=R[k++]=ST.top().s;
		}
		ST.pop();
	}
	printf("%lld\n",r);
	printf("%d%c",k,k?' ':'\n');
	for(i=0;i<k;i++)
		printf("%lld%c",R[k-i-1],i==k-1?'\n':' ');

}