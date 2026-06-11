#include <bits/stdc++.h>
#define ll long long
using namespace std;
int a[105];
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            for(int k=j+1;k<=n;k++)
            {
                set<int>q;
                q.clear();
                q.insert(a[i]);
                q.insert(a[j]);
                q.insert(a[k]);
                if(q.size()==3&&a[i]+a[j]>a[k]&&abs(a[i]-a[j])<a[k])
                    cnt++;
            }
        }
    }
    cout<<cnt;
    return 0;
}
