#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mod 1000000007

int main()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    int c=1;
    char ch=s[0];
    string d="";
    d+=s[0];
    for(int i=1;i<s.size();i++)
    {
        if(s[i]==ch)
            c++;
        else
        {
            c=1;
            ch=s[i];
            d+=s[i];
        }
    }
   int q=d.size();
   cout<<q<<"\n";
    return 0;
}
