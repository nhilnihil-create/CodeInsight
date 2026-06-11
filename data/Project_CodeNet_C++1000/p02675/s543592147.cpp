#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int N=5e4+9;
const int mod=1e9+7;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin>>s;
    int x=s[s.size()-1]-'0';
    if(x==2||x==4||x==5||x==7||x==9)cout<<"hon";
    if(x==3)cout<<"bon";
    if(x==0||x==1||x==6||x==8)cout<<"pon";
   

    
    
   

}
    