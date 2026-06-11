#include<iostream>
#include<vector>
#define lli long long int
#include<climits>
#include<unordered_map>
#include<algorithm>
#include<bitset>
#include<map>
#include<cmath>
#include<queue>
#define pb push_back
#define N (int)(1e5)
using namespace std;
using namespace std;
int main()
{
    int n,k;
    cin>>n>>k;
    lli ans=0;
    vector<lli>arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    sort(arr.begin(),arr.end(),greater<int>());
    for(int i=k;i<n;i++)
    {
        ans = ans+arr[i];
    }
    cout<<ans<<endl;
    
    
    

}

