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
	int h,n,a;
	cin>>h>>n;
	for (int i = 0; i < n; ++i)
	{
		cin>>a;
		h-=a;
		if(h<=0){
		cout<<"Yes"<<endl;	
		return 0;
		} 
		
	}
	cout<<"No"<<endl;
   return 0;
}
