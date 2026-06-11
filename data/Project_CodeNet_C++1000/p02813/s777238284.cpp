#include <iostream>
#include <algorithm>
#include <cstdio>
#include <sstream>
// #include <cmath>
// #include <map>
// #include <set>
// #include <deque>
// #include <stack>
// #include <vector>
using namespace std;
#define debug freopen("in.txt","r",stdin),freopen("out.txt","w",stdout);
#define ios ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
// #define PI acos(-1)
typedef long long ll;
const ll mod=1e9+7;

int N,P[20],Q[20],S[20];
int main()
{
	//debug;
	ios;
	cin>>N;
	for(int i=0;i<N;i++)
	{
		cin>>P[i];
		S[i]=P[i];
	}
	for(int i=0;i<N;i++) cin>>Q[i];
	sort(S,S+N);
	int cnt=1;
	int i;
	int a=0,b=0;
	do
	{
		for(i=0;i<N;i++)
		{
			if(S[i]!=P[i])
				break;
		}
		if(i==N) a=cnt;
		
		for(i=0;i<N;i++)
		{
			if(S[i]!=Q[i])
				break;
		}
		if(i==N) b=cnt;
		cnt++;
	}while(next_permutation(S,S+N));
	cout<<abs(a-b);
    return 0;
}
