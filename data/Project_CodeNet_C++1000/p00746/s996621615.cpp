#include <cstdio>
#include <utility>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>
#define REP(i,n) for(int i=0;i<n;i++)
typedef long long ll;
using namespace std;
typedef vector<ll> vl;
typedef pair<ll,ll> pll;
typedef vector<pll> vpll;
typedef vector<string> vs;

int main() 
{
	int n;
	while(cin >> n && n!=0)
	{
		
		int a[400][400]={};
		int b[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
		int x[200]={};
		int y[200]={};
		x[0]=200;
		y[0]=200;
		a[x[0]][y[0]]=1;
		
		REP(i,n-1)
		{
			int s,t;
			cin >> s >> t;
			x[i+1] = x[s] + b[t][0];
			y[i+1] = y[s] + b[t][1];
			a[x[i+1]][y[i+1]]=1;
		}
		
		int w(0),h(0);
		REP(i,400)
		{
			int tmp(0);
			REP(j,400)if(a[i][j]==1){tmp++;break;}
			if(tmp>0){w++;}
		}
		
		REP(i,400)
		{
			int tmp(0);
			REP(j,400)if(a[j][i]==1){tmp++;break;}
			if(tmp>0){h++;}
		}
		
		cout << w << " " << h << endl;
	}
	return 0;
}