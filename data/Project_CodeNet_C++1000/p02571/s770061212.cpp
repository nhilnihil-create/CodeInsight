/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

int main()
{
    long long ans,cnt,i,j,g;
    string s,t;
    ans=1000000;
    cin>>s>>t;
    for(i=0;i<s.length();i++)
    {
        cnt=0;g=5;
        for(j=0;j<t.length();j++)
        {
          if(i+j>=s.length()){g=0;break;}
            if(s[i+j]!=t[j]){cnt++;}
        }
      if(g==0){continue;}
        ans=min(ans,cnt);
    }
    cout<<ans;
    return 0;
}
