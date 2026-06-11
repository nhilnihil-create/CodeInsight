#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define lef(x) (x<<1)
#define rig(x) (lef(x)+1)
#define int long long
pair<string,int> a[60];
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    for (int i = 0; i < n; ++i)
    {
    	cin>>a[i].first>>a[i].second;
    }
    int x=0,t=0;
    string sx;
    cin>>sx;
    for (int i = 0; i < n; ++i)
    {
    	if(t)
    		x+=a[i].second;
    	if(a[i].first==sx)
    		t=1;
    }
    cout<<x<<"\n";
    return 0;   
}