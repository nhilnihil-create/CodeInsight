#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int main()
{
    string s;
    cin>>s;
    long long q,i,x,y,a=0,j;
    char z;
    cin>>q;
    for(i=1;i<=q;i++)
    {
        cin>>x;
        if(x==1)
        {
           a++;
        }        
        else if(x==2)
        {
           cin>>y;
           cin>>z;
           if(y==1)
           {
              if(a%2!=0)
              {
                 s.push_back(z);
              }
              else
              {
                 s=z+s;
              }
           }
           else if(y==2)
           {
              if(a%2!=0)
              {
                 s=z+s;
              }
              else
              {
                 s.push_back(z);
              }
           }
        }
    }
    if(a%2==0)
    {
        cout<<s<<endl;
    }
    else
    {
       for(j=s.size()-1;j>=0;j--)
       {
           cout<<s[j];
       }
       cout<<endl;
    }
    return 0;
}