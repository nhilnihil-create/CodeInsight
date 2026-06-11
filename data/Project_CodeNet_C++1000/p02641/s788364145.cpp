#include<bits/stdc++.h>
using namespace std;
int main()
{
    int x,n;
    cin>>x>>n;
    vector<int> p(n);
    unordered_map<int,bool> isPresent;
    for(int i=0;i<n;i++)
    {
        cin>>p[i];
        isPresent[p[i]] = true;
    }
    int ans=x;
    for(int i=0;i<1000;i++)
    {
        int right = x+i;
        int left = x-i;
        if(isPresent.find(left)==isPresent.end())
        {
            ans = left;
            break;
        }
        if(isPresent.find(right)==isPresent.end())
        {
            ans = right;
            break;
        }
    }
    cout<<ans<<endl;
}
