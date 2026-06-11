#include<bits/stdc++.h> 
using namespace std;
typedef long long ll;
const int N=2e5+5;
int n;
ll A[N];
ll minv;
ll ans;
int main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>A[i];
    for(int i=1;i<=n;i++)
    {
        if(i==1)
            minv=A[i];
        else
            {
                if(minv>=A[i])
                    ans+=minv-A[i];
                else
                    minv=A[i];
            }
    }
    cout<<ans<<endl;
}