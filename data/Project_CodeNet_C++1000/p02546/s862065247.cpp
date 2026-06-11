#include <bits/stdc++.h>
#include<stdlib.h>
#include<iostream>
#include<math.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define ll long long
#define INF 2000000000
#define Min(a,b) (a<b?a:b)
#define Max(a,b) (a>b?a:b)
#define PI 3.1415926535897932
using namespace std;




int main()
{
IOS;
string s;
cin>>s;
// cout<<(*(s.end()-1));
if(*(s.end()-1)=='s')
	cout<<(s+"es");
else
	cout<< (s + "s");

return 0;
}