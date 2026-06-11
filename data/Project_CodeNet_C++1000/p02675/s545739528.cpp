#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(30);
#define ll long long
#define pi 3.14159265359
using namespace std;

int main()
{
    IOS;
    string s;
    cin>>s;
    int x=s.size()-1;
    if(s[x]=='3') cout<<"bon";
    else if (s[x]=='0' || s[x]=='1' || s[x]=='6' || s[x]=='8') cout<<"pon";
    else cout<<"hon";
    return 0;
}