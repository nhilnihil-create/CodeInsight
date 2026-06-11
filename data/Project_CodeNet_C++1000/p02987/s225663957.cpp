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
#include<functional>
using namespace std;
typedef long long ll;
typedef pair<int,int>P;
string S;
bool ch(int a,int b)
{
	return S[a]==S[b];
}

int main()
{
	cin>>S;
	if((ch(0,1)&&ch(2,3)&&!ch(0,2))||(ch(0,2)&&ch(1,3)&&!ch(0,1))||(ch(0,3)&&ch(1,2)&&!ch(0,1)))
	{
		cout<<"Yes"<<endl;
	}
	else
	{
		cout<<"No"<<endl;
	}
}