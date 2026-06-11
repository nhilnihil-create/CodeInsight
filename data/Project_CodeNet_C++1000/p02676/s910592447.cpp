#include <bits/stdc++.h>
#include<cstring>
using namespace std;
int main()
{
    int i,k;
    string s,c="";
    cin>>k>>s;

     if(s.size()>k)
    {
        for(i=0;i<k;i++){
            c=c+s[i];
        }
        cout<<c;
            cout<<"...";


    }
    else
    {

        cout<<s;
        return 0;
    }
   return 0;
}
