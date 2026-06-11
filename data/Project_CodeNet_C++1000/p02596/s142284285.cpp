#include <bits/stdc++.h>
#define ll long long int
#define li long int
#define ld long double
const ll len=1e6+1;
using namespace std;

int main()
{
    int k;
    cin>>k;
    if(k%2==0 || k%5==0)
    {
        cout<<-1<<endl;
    }
    else
    {
        int curr=7%k;
        int ans=1;
        while(curr!=0)
        {
            curr=curr*10+7;
            curr%=k;
            ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}
