#include<bits/stdc++.h>
# define rep(i,n)for(i=0; i<n; i++)
using namespace std;
int main()
{
    string s1,s2,s3;
    cin>>s1>>s2;
    s3 = s2.substr(0,s2.size());
     s3 = s2.substr(0,s1.size());
    if(s1==s3){cout<<"Yes"<<endl;return 0;}
    else {cout<<"No"<<endl;return 0;}
}
