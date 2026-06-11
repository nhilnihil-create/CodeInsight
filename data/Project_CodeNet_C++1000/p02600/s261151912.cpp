#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long 
#define mp make_pair
#define pb push_back
#define gcd(a, b)   __gcd(a, b)
#define lcm(a, b)  ((a)*((b)/gcd(a,b)))
#define pi 3.14159265358979323846
#define reus ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int32_t main()
{
	reus;

//	#ifndef ONLINE_JUDGE
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
//	#endif
    
    int n;
  cin>>n;
  if(n>=400&&n<=599)
    cout<<"8"<<endl;
  else if(n>=600&&n<=799)
    cout<<"7"<<endl;
  else if(n>=800&&n<=999)
    cout<<"6"<<endl;
  else if(n>=1000&&n<=1199)
    cout<<"5"<<endl;
  else if(n>=1200&&n<=1399)
    cout<<"4"<<endl;
  else if(n>=1400&&n<=1599)
    cout<<"3"<<endl;
  else if(n>=1600&&n<=1799)
    cout<<"2"<<endl;
  else if(n>=1800&&n<=1999)
    cout<<"1"<<endl;
    
	return 0;
}