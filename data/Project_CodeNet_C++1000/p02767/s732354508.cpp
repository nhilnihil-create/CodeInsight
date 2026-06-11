#include<bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

#define loop(i,n)for(i=0;i<n;i++)
#define INF 1000000000
using ll = long long int;
typedef pair<int,int> pii;
typedef vector<pii> vii;
typedef vector<int> vi;





int main()
{
    IOS;
    //freopen("inputfile.txt","r",stdin);
    int n;cin>>n;
    int ar[n];
    for(int i=0;i<n;i++)cin>>ar[i];
    int ans = 100000000;
    for(int i=1;i<100;i++)
    {
        int sum = 0;
        for(int j=0;j<n;j++)sum+=((ar[j]-i)*(ar[j]-i));
        ans = min(ans,sum);
    }
    cout<<ans<<endl;
    return 0;
}
