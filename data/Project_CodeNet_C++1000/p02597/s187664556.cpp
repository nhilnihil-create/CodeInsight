#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define infin ll (pow(10,9)+7);
typedef unsigned int ui;
int main()
{
    int n;
    string s;
    cin>>n;
    cin>>s;
    int count=0,temp=0;
    for(ui i=0;i<s.size();i++)
    {
        if (s[i]=='W')
         temp+=1;
    }
    for(ui i=s.size()-temp;i<s.size();i++)
    {
        if (s[i]=='R')
         count++;
    }
    cout<<count<<endl;
}