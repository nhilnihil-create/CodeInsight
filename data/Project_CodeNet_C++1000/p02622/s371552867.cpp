#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a; i<b; i++)
#define lli long long
#define pb push_back
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int main()
{
    fast
    string s1, s2;
    cin>>s1>>s2;
    int count =0;
    rep(i,0,s1.size()){
        if(s1[i]!=s2[i]){
            count++;
        }
    }
    cout<<count;
    return 0;
}
