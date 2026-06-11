#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int a,b,c;
	cin>>a>>b>>c;
    if(a==b && b!=c)
     cout<<"Yes";
    else if(b==c && b!=a)
     cout<<"Yes";
    else if(a==c && b!=a)
     cout<<"Yes";
    else
     cout<<"No";
    return 0;
	
}