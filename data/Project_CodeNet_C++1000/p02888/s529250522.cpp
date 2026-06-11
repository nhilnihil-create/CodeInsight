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
    vector<int> v(n);
    for(int i=0;i<n;++i)
    {
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    int ans = 0;
    for(int a=0;a<n;++a)
    {
        int k = a + 2;
        for(int b=a+1;b<n;b++)
        {
           
            while(k < n && v[a] + v[b] > v[k])
            {
                ++k;
            }
            if(k > b)
            {
                ans += k - b - 1;
            }
            
        }
    }
    cout<<ans<<endl;
    
    return 0;

}
