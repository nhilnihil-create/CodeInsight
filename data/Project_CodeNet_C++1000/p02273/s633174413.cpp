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
#define PI 3.14159265358
using namespace std;
typedef long long ll;
typedef pair<double,double>P;
queue<P>S;
P s,t;
int N;
int main()
{
	scanf("%d",&N);
	S.push(make_pair(0,0));
	S.push(make_pair(100.0,0));
	for(;N--;)
	{
		s=S.front();S.pop();
		queue<P>T;
		do
		{
			t=S.front();S.pop();
			P s1=make_pair(s.first+(t.first-s.first)/3,s.second+(t.second-s.second)/3);
			P s2=make_pair(s.first+(t.first-s.first)/3*2,s.second+(t.second-s.second)/3*2);
			
			T.push(s);
			T.push(s1);
			
			T.push(make_pair(s1.first+(s2.first-s1.first)*cos(PI/3.0)-(s2.second-s1.second)*sin(PI/3.0),
							s1.second+(s2.first-s1.first)*sin(PI/3.0)+(s2.second-s1.second)*cos(PI/3.0)));
			T.push(s2);
			s=t;
		}while(!S.empty());
		T.push(t);
		S=T;
	}
	for(;!S.empty();)
	{
		printf("%lf %lf\n",S.front().first,S.front().second);
		S.pop();
	}
	return 0;
}