#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define SZ(X) ((int)(X).size())
#define endl "\n";
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
   int a,b,c,d;
   cin>>a>>b>>c>>d;
    int x = (a+d-1)/d ;//floor
    int y = (b+c-1)/b;
    if(x>=y) cout<<"Yes"; else cout<<"No";
   return 0;
}
