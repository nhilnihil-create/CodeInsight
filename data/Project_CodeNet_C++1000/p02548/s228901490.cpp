#include <bits/stdc++.h>
using namespace std;
int main()
{
	// #ifndef ONLINE_JUDGE
	// freopen("input.txt","r",stdin);
	// freopen("output.txt","w",stdout);
	// #endif 
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    //cin>>t;
  	t=1;
    while(t--)
    {
    	int n;
    	cin>>n;
    	int b;
    	int count=0;
    	for(int a=1;a<n;a++)
    	{
    		b=floor((n-1)/a);
    		count+=b;
    	}
    	cout<<count<<endl;
    }
}