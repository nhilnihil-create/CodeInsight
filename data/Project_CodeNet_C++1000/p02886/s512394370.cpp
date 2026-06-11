#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define mod 1000000007
#define wi while
#define vl vector<ll>
#define vi vector<int>
#define map map<char,ll>
#define endl "\n"
const int mxN = 200001;
int main()
{
    
    int n;
    cin>>n;
    int d[n+1];
    for(int i=1;i<=n;++i)cin>>d[i];
        int sum = 0;
    for(int i=1;i<=n;++i)
    {
        for(int j=i+1;j<=n;j++)
        {
            sum += d[i] * d[j];
        }
    }
    cout<<sum<<endl;
    
    return 0;

}
