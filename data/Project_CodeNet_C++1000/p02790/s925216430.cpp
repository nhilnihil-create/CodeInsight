#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define SZ(X) ((int)(X).size())
#define endl "\n";
void repeat(int x,int y){
	while(x--) cout<<y;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
   int a,b;
   cin>>a>>b;
   if(a>=b) repeat(a,b); else repeat(b,a);	

   return 0;
}
