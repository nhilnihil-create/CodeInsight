//BISMILLAH
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
   int a,b,c,d,minus1,minus2,res=0;
   cin>>a>>b>>c>>d;
   int count1=0,count2=0;
   while(c-b>0)
   {
       c=c-b;
       count1++;
   }
   while(a-d>0)
   {
       a=a-d;
       count2++;
   }
  // cout<<count1<<count2<<endl;

   if(count1==count2) cout<< "Yes"<<endl;
   else if(count1>count2) cout<< "No"<<endl;
   else if(count1<count2) cout<< "Yes"<<endl;

}
