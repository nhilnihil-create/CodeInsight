#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
     string str,s;

     cin>>s>>str;
     int t=0,i;

     for(i=0;i<s.size();i++){

        if(s[i]==str[i])t++;

     }

     cout<<t<<endl;
    return 0;
    }