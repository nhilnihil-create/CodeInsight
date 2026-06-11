#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
   string s;
   cin>>s;
   string s1;
   for(int i=s.length()-1;i>=0;i--)
   {
       s1=s1+s[i];
   }
   int count=0;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]!=s1[i])
            count++;
    }
    cout<<count/2<<endl;

    return 0;
}
