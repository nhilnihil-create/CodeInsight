#include <iostream>
#include <bits/stdc++.h>
#define ll long long 
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define pii pair<ll , ll>
#define mpi make_pair
#define F first
#define S second
#define pb push_back

bool comp1(pii a , pii b)
{
    return atan2(a.S , a.F) < atan2(b.S , b.F) ;
}

int main()
{   
    //fastio;
    int n;
    cin>>n;

    vector<pii> curr;

    for(int i = 0 ;i<n;i++)
    {
        int a , b ;
        cin>>a>>b;
        if(a == 0 && b== 0)continue;
        curr.pb(mpi(a , b));
    }

    sort(curr.begin() , curr.end() , comp1);

    ll ans =0;
    ll x =0, y = 0;
    int siz= curr.size();
    ll temp;
    // for(int i = 0 ;i<siz;i++)cout<<curr[i].F<<" "<<curr[i].S<<endl;
    for(int i = 0 ;i<siz;i++)
    {
        x = curr[i].F;
        y = curr[i].S;
        int j =(i+1)%siz;
        temp =x*x+y*y;
        ans = max(temp, ans);
        while(j != i)
        {   
            x = x+curr[j].F;
            y = y+curr[j].S;
            temp = x*x + y*y;
            ans = max(temp , ans);
            j = (j+1)%siz;
        }
    }

    long double ret = sqrtl(ans);
    
    cout<<setprecision(30)<<ret<<endl; 

    return 0;
}
