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
	string s,a="ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    int n,p;
    cin>>n>>s;
if(n==0){
	cout<<s; return 0;
}
    for (int i = 0; i < SZ(s); ++i)
    	{
    		 p=s[i]-'A';
    		 p+=n;
    		 cout<<a[p%26];
    	}	

   return 0;
}
