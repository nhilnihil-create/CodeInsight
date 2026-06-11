#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long int
#define PI 3.141592653589


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    double ans=0,A;
    for(int i=0;i<n;i++)
    {
        cin>>A;
        ans+=1/A;
    }
    ans=1/ans;
    cout<<setprecision(16)<<ans<<endl;


    return 0;
}


