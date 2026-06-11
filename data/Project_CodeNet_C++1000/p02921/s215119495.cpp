#include<bits/stdc++.h>
#define ll long long int 
using namespace std;
int main()
{
      string s,s1;
    ll c=0;
     cin>>s>>s1;
       for(int i=0; i<s.size(); i++){
        if(s[i]==s1[i])c++;
        }
    cout<<c<<endl;

}