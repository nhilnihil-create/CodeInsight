#include<bits/stdc++.h>
#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<cmath>
#include<math.h>
#include<queue>
#define mem(x) memset(x,0,sizeof(x)) 
#define sca(x) scanf("%d",&x)
#define scaa(x,y) scanf("%d%d",&x,&y)
#define inf 0x7f7f7f7f
#define io ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#pragma GCC optimize(2)
using namespace std;
const double pi=acos(-1); 
const double eps=1e-6;
typedef pair<long,long> pll;
typedef pair<int,int> pii;
typedef long long ll;
typedef pair<string,string> pcc;
int main()
{
	int l,r,d;
	cin>>l>>r>>d;
	cout<<r/d-(l-1)/d<<endl;
}