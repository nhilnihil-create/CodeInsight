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
	int n,a;
	cin>>n;
	for (int i = 0; i < n; ++i)
		{
			cin>>a;
			if(a%2==0)
			if(a%3!=0 && a%5!=0){
				cout<<"DENIED"<<endl;
				return 0;
			}
		}	
		cout<<"APPROVED"<<endl;

   return 0;
}
