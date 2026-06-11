//Author:  Pranta
//Date:    2020-Sep-11
//Problem: B_Substring
#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
using namespace std;
void solve()
{
    string s,t;
    cin>>s>>t;
    int c=0,ans=0;
    for(int i=0;i<=s.size()-t.size();++i){
        c=0;
        for(int j=0;j<t.size();++j){
        if(s[j+i]==t[j]){
            c++;
        }
        }
    ans=max(c,ans); 

    }
    cout<<t.size()-ans;
}
int main()
{
    fast;
    int t;
    //cin>>t;
    //while(t--)
    solve();
}