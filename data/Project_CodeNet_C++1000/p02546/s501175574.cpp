#include "bits/stdc++.h"
using namespace std;
#define MODULO 1000000007
#define PI 3.14159265359
typedef long long int ll;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
	cout.tie(NULL);
	string s;
	cin>>s;
	int n=s.length();
	cout<<s;
	if(s[n-1]=='s')
	cout<<"es";
	else
	cout<<"s";	
    return 0;
}
