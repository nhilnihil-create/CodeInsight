#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int len = s.length();
    int k = s[len-1]-'0';
 //   cout<<k;
    if(k==3) puts("bon");
    else if(k==0 || k==1 || k==6 || k==8) puts("pon");
    else puts("hon");
}
