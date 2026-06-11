//Solution By SlavicG
#include <bits/stdc++.h>
using namespace std;
 
#define ll                          long long
 
#define forn(i,n)                   for(int i=0;i<n;i++)
#define all(v)                      v.begin(), v.end()
#define rall(v)                     v.rbegin(),v.rend()
	
#define pb                          push_back
#define sz(a)                       (int)a.size()
#define mp                          make_pair
 
#define   endl                       "\n"
#define fastio                       ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
 
int main()
{
	unordered_map<int,bool> ac;
	unordered_map<int,int> f;
	int n,m;
	cin >> n >> m;
	int cnt  = 0;
	int wa = 0;
	for(int i = 0;i<m;i++)
	{
		int a; string c;
		cin >> a >> c; 
		if(!ac[a])
		{
			if(c == "AC"){
				cnt++;
				wa += f[a];
				ac[a] = true;
			}else{
				f[a]++;
			}
		}
	}
	cout << cnt << " " << wa << endl;
}