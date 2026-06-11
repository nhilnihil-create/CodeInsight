#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define ll long long int 
int main()
{
    string s;
    cin>>s;
    if(s[0]=='S')
    cout<<"Cloudy";
    else if(s[0]=='C')
    cout<<"Rainy";
    else
    cout<<"Sunny";

    return 0;
}
