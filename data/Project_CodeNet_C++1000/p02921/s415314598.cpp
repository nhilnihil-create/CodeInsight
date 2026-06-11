#include<bits/stdc++.h>
using namespace std;
#define ll "%I64d"
const int max1=100010;
//long long a[max1],b[max1];
int main()
{
   string s1,s2;
   cin>>s1>>s2;
   int k=0;
   for(int i=0;i<s1.size();i++)
   {
       if(s1[i]==s2[i])
       {
           k++;
       }
   }
   cout<<k<<"\n";
}

