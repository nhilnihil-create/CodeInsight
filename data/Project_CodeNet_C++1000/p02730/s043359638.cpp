


#include<bits/stdc++.h>
using namespace std;
#define ll long int 

int  main()
{  

    string s;
    cin>>s;
    int n=s.length();
    int l1=(n-1)/2;
    int l2=(n+3)/2;
    bool pahla=true;
    bool dusra=true;
    for(int i=0, j=l1-1;i<=j;i++, j--)
    {
        if(s[i]!=s[j])
        {
         pahla=false;
         break;
        }
    }
    if(l2<=n)
    {
    for(int i=l2-1, j=n-1;i<=j;i++, j--)
    {
        if(s[i]!=s[j])
        {
            dusra=false;
            break;
        }
    }
    }
    else{
        dusra=false;
    }
    bool thisra=true;
    for(int i=0,j=n-1;i<=j;i++, j--)
    {
        if(s[i]!=s[j])
        {
            thisra=false;
        }
    }
    if(pahla&&dusra&&thisra)
    {
        cout<<"Yes"<<endl;
    }
    else
    {
        cout<<"No"<<endl;
    }




    return 0;
}