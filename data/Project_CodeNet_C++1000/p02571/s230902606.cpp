#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    string x1,x2;
    cin>>x1>>x2;
    int ans=x2.size();
    for(int i=0;i<=x1.size()-x2.size();i++){
        int diff=0;
        for(int j=0;j<x2.size();j++){
            if (x2[j]!=x1[j+i]){
                diff++;
            }
        }
        ans=min(ans,diff);
    }
    cout<<ans<<endl;
}