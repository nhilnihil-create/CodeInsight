#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int main()
{
    ull n;
    string s="";
    cin>>n;
    while(n>0)
    {
        if(n%26==0)
            {s='z'+s;n-=1;}
        else
            {char x=((n%26)-1)+'a';s=x+s;}

        n/=26;
    }
        cout<<s;
}
