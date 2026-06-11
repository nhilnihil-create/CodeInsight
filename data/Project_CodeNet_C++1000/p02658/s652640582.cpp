#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long int
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
    int t;
    t = 1;
    for(int i=0;i<t;i++)
    {
        int n;
        cin>>n;
        ll arr[n];
        ll prod = 1;
        int x = 0;
        for(int j=0;j<n;j++)
        {
            cin>>arr[j];
            if(arr[j]==0)
            {
                x = 2;
                break;
            }
        }
        for(int j=0;j<n && x==0;j++)
        {
            if(prod>1000000000000000000/arr[j])
            {
                x = 1;
                break;
            }
            else
            {
                prod*=arr[j];
            }
        }
        if(x==2)
        {
            cout<<0;
        }
        else if(x==1)
        {
            cout<<"-1";
        }
        else
        {
            cout<<prod;
        }
    }
    return 0;
}