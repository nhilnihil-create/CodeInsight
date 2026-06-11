#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long i,n,c=1;
    string s;
    cin>>n>>s;
      for(i=0;i<s.size()-1;i++)
      {
        if(s[i]!=s[i+1])
          c++;

      }

    cout<<c<<endl;

return 0;
}
