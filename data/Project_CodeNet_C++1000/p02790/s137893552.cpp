
#include<bits/stdc++.h>
using namespace std;


#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);  ///for fasting input and output using cin,cout(only)
#define endl '\n'

int main()

{
    optimize();
   int a,b;
   cin>>a>>b;

    string sa=to_string(a);
    string cpa=sa;
    string sb=to_string(b);
    string cpb=sb;


    for(int i=0;i<b-1;i++)
    {
        sa=sa+cpa;

    }
     //cout<<sa;
    //cout<<endl;
     for(int i=0;i< a-1;i++)
         {
             sb+=cpb;


         }
         //cout<<sb;
         if(a==b)
         {
             cout<<sa;
         }
         else
         {
              if(sa<sb)
            cout<<sa;
            else cout<<sb;
         }

 return 0;
}
