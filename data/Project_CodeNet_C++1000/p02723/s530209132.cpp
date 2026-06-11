#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i,j,len;
    string str;
    cin>>str;
    len=str.length();

     if(str[len-4]==str[len-3] && str[len-2]==str[len-1])
     {
         cout<<"Yes"<<endl;
     }
    else
    {
        cout<<"No"<<endl;
    }

 return 0;
}
