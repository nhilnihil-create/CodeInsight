/*Author : Krishna*/

#include<iostream>
#include<unordered_map>
#include<queue>
#include<vector>
#include <cmath>
#include <stack>
#include <unordered_set>
#include <algorithm>
/* 97 to 122*/
using namespace std;

void solve()
{
    string S,T;
    cin>>S>>T;
    int ans =(int) T.size();
    for(int start =0;start<=S.size()-T.size();start++)
    {
        int diff=0;
        for(int i=0;i<T.size();i++)
        {
            if(T[i]!=S[start+i])
            {
                diff++;
            }
        }
        ans = min(ans,diff);
    }
    cout<<ans;

    
    
}
int main()
{
    int t;
    t=1;
    while(t--)
    {
        solve();
    }
}


