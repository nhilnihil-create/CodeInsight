#include <bits/stdc++.h>
using namespace std;
int main()
{
 string s;

    cin>>s;
     int len=s.size();
    int n=0,i=0;
    int j=len-1;
while(i<len/2)
{
      if(s[i]!=s[j])
          n++;
          i++;
          j--;
        }
    cout<<n;
}