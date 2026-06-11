//Solution By SlavicG
#include <bits/stdc++.h>
using namespace std;
 
#define ll                          long long
 
#define forn(i,n)                   for(int i=0;i<n;i++)
#define all(v)                      v.begin(), v.end()
#define rall(v)                     v.rbegin(),v.rend()
	
#define pb                          push_back
#define sz(a)                       (int)a.size()
 
#define   endl                       "\n"
#define fastio                       ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int  main()
{
	int n;
	cin >> n;
	int x = n % 10;
	if(x==2 || x== 4 || x==5 || x== 7 || x == 9){
		cout << "hon";
	}
	if(x==0||x==1||x==6||x==8){
		cout << "pon";
	}
	if(x==3)
		cout << "bon";
}