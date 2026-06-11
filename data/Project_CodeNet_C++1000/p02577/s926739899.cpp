#include<bits/stdc++.h>
using namespace std;


int main()
{
    string a;
    int ans=0;
    cin>>a;
    for(int i=0;i<a.size();++i) {
        ans=ans*10+a[i]-'0';
        ans%=9;
    }
    if(!ans) puts("Yes");
    else puts("No");
}