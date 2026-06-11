#include<bits/stdc++.h>
#define ull unsigned long long
# define ll long long
# define mod 1000000007LL 
using namespace std;
int main()
{
     ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    map<string,int>ans;
    ll num=7;
    ans["SUN"]=7;
    ans["MON"]=6;
    ans["TUE"]=5;
    ans["WED"]=4;
    ans["THU"]=3;
    ans["FRI"]=2;
    ans["SAT"]=1;
    string s;
    cin>>s;
    cout<<ans[s];



    
    return 0;
}