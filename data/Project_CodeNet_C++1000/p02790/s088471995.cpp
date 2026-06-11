#include<bits/stdc++.h>
using namespace std;

int main() 
{
    int a,b;
    cin>>a>>b;

    string A(to_string(a)),B(to_string(b));
    for (int i = 1; i < b; i++)
    {
        A+=to_string(a);
    }
    for (int i = 1; i < a; i++)
    {
        B+=to_string(b);
    }
    vector<string>ans={A,B};
    sort(ans.begin(),ans.end());
    cout<<ans[0]<<endl;
    return 0;
}