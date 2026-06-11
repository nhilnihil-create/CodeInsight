#include<iostream>
#include<fstream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cmath>
#include<map>
#include<set>
#include<bitset>
using namespace std;
#define int long long
#define mod 1000000009
#define inf 4444444444444444444
#define mn 150005

int n;
int A[1005][1005];

void color(vector <int> V, int col)
{
	if (V.size()==1) return;
	vector <int> V1={};
	vector <int> V2={};
	for (int i=0; i<V.size()/2; i++) V1.push_back(V[i]);
	for (int i=V.size()/2; i<V.size(); i++) V2.push_back(V[i]);
	for (int i:V1) for (int j:V2) A[i][j]=col;
	color(V1, col+1);
	color(V2, col+1);
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n;
	vector <int> vv={};
	for (int i=1; i<=n; i++) vv.push_back(i);
	color(vv, 1);
	for (int i=1; i<=n; i++)
	{
		for (int j=i+1; j<=n; j++) cout<<A[i][j]<<" ";
		cout<<"\n";
	}
}