#include<iostream>
#include<string>
using namespace std;
int main()
{
   string s,t;
   cin>>s>>t;
   int c=0;
   int l=s.size(),k=t.size();
   if(l+1==k)
   {
       for(int i=0;i<l;i++)
       {
           if(s[i]!=t[i])
           {
               c++;
           }


       }
                  if(c>0)
           {
               cout<<"No"<<endl;
           }
           else{cout<<"Yes"<<endl;
           }
   }
   else{
    cout<<"No"<<endl;
   }




    return 0;

}
