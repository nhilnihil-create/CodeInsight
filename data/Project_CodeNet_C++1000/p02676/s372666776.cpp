#include<bits/stdc++.h>
using namespace std;


int main()
{
   int k;cin>>k;
   string s; cin>>s;
   int len = s.size();
   if(len>k)
     {for(int i= 0;i<k;i++)
        cout<<s[i];
       cout<<"..."<<endl;

     }
     else{
        cout<<s<<endl;
       }

}