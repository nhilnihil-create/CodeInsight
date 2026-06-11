#include<bits/stdc++.h>
using namespace std;
#define ld long double
#define pb push_back
#define mp make_pair
#define fi(i,start,end) for(int i=start; i < end ; ++i)
#define Fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
//#define mod 100000000

using namespace std;



int main()
{
    int n,k;
    cin>>n>>k;
    int temp;
    vector<int> v;
    fi(i,0,n)
    {
        cin>>temp;
        v.pb(temp);
    }
    sort(v.begin(),v.end());
    int ans=0;
    fi(i,0,k)
    {
        ans+=v[i];
    }
    cout<<ans;

}







