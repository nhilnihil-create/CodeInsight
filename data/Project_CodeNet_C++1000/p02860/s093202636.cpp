#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,c=0;
    string s;

    cin>>n;
  cin>>s;
      for(i=0;i<n/2;i++)
      {
          if(s[i]==s[(n/2)+i])
            c++;
      }
      if(n%2==1)
        cout<<"No"<<endl;
  else if(c==n/2)
    cout<<"Yes"<<endl;
  else
    cout<<"No"<<endl;

   return 0;
}
