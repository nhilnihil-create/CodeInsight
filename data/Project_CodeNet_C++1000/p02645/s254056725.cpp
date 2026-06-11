#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int main()
{
   string s;
   cin>>s;
   int cnt=0;
   for(int i=0;i<s.length();i++)
   {

       if(cnt<3)
       {  cnt++;
          cout<<s[i];
   }
   }

 return 0;
}

