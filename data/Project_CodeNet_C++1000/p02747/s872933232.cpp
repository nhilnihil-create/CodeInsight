#include<bits/stdc++.h>
using namespace std;
int main()
{  string str;
    cin>>str;
    if(str.size()%2!=0)
    {cout<<"No";exit(0);}
    else
    {  for(int i=0;i<str.size();i++)
        {  if(i%2==0)
            {  if(str[i]!='h')
                {cout<<"No";exit(0);}
            }
            else
            {if(str[i]!='i')
                {cout<<"No";exit(0);}}
        }cout<<"Yes";
    }
}