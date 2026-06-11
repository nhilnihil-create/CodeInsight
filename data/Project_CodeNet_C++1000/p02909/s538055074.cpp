#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;

int main()
{
string s;
cin>>s;
if(s.compare("Sunny")==0)cout<<"Cloudy"<<endl;
if(s.compare("Cloudy")==0)cout<<"Rainy"<<endl;
if(s.compare("Rainy")==0)cout<<"Sunny"<<endl;
return 0;
}
