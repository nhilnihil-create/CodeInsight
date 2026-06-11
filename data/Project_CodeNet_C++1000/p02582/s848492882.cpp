#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;

typedef vector<long long> vi;


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin>>s;
    int ans=0;
    if(s[0]=='R' && s[1]=='R' && s[2]=='R') ans=3;
    else if(s[0]=='R' && s[1]=='R') ans=2;
    else if(s[1]=='R'&& s[2]=='R') ans=2;
    else if(s[0]=='R' || s[1]=='R' || s[2]=='R') ans=1;
    else ans=0;
    cout<<ans;
}