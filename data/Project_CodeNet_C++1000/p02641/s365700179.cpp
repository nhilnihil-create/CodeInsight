#include<bits/stdc++.h>
using namespace std;
int main()
{
    int k,n;
    cin>>k>>n;
    if(n==0)
    {
        cout<<k<<endl;
        return 0;
    }
    set<int> s;
    for(int i = 0;i<n;i++)
    {
        int x;
        cin>>x;
        s.insert(x);
    }
    int i = k,j = k;
    int ans;
    int m = INT_MAX;
    int flag  = 1;
    while(flag)
    {
        if(abs(k-i)<m)
        {
            if(s.find(i)==s.end())
            {
            flag = 0;
            m = abs(k-i);
            ans = i;
            }
            i--;
        }
        if(abs(k-j)<m)
        {
                 if(s.find(j)==s.end())
        {
        flag = 0;
        m = abs(k-j);
            ans = j;
            }
            j++;

            }
            
        }

    
    cout<<ans;
    
    
    return 0;
}