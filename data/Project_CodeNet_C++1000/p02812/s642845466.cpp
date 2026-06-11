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

int main()
{
	//debug;
	ios;
	int N,num=0;
	string S;
	cin>>N>>S;
	for(int i=0;i<S.size()-2;i++)
	{
		if(S[i]=='A'&&S[i+1]=='B'&&S[i+2]=='C')
			num+=1;
	}
	cout<<num;
    return 0;
}
