#include <bits/stdc++.h>
using namespace std ;
using ll = long long ;
int main()
{  ll a,b,c,d ;
 cin>>a>>b>>c>>d;
	if(a>=d) cout<<d<<endl;
	else if(a+b>=d) cout<<a<<endl;
	else cout<<a-(d-a-b)<<endl;
    return 0 ;
}
