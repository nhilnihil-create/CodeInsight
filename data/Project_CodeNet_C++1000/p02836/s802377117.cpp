#include<bits/stdc++.h>
using namespace std;

int main() 
{
    string S;
    cin>>S;
    auto S1 = S.substr(0,(S.size()/2));
    auto S2=S.substr((S.size()/2));
    reverse(S2.begin(),S2.end());
    int ans=0;
    for (int i = 0; i < S.size()/2; i++)
    {
        int end =S.size()/2;

        if(S1[i]!=S2[i])
        {
            ++ans;
        }
    }
    
    cout<<ans<<endl;
}