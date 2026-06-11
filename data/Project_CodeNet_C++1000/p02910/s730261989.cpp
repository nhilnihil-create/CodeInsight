#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    string s;
    cin>>s;
    int i=0;
    for(i=0;i<s.size();i++) {
        if(i%2==0) {
            if(s[i]=='L')
                break;
        }
        if(i%2==1) {
            if(s[i]=='R')
                break;
        }
    }
    if(i==s.size())
        cout<<"Yes\n";
    else
        cout<<"No\n";
}