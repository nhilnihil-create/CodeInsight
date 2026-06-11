



#include<bits/stdc++.h>
using namespace std;



//defines...
#define ll long long
#define tata return;
#define pb push_back
#define mp make_pair
#define in insert
#define run ios_base::sync_with_stdio(false);cin.tie(NULL);
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl;
#define vec vector<ll>
#define setl set<ll>
#define mapl map<ll,ll>
#define shunno cout<<0<<endl;
#define ek cout<<1<<endl;
#define pi 2*acos(0.0)1
#define hobena cout<<-1<<endl;




//typedefs...
typedef pair<ll,ll>pll;

//const..
//const ll fx[]={0,1,0,-1};
//const ll fy[]={1,0,-1,0};
const ll mod=1e9+7;

/*ll ncr(ll n, ll k)
{
    ll res = 1;


    if (k > n - k)
        k = n - k;

    for (int i = 0; i < k; ++i) {
        res *= (n - i);
        res /= (i + 1);
    }

    return res;
}
*/

void oka()
{
    ll n,i,j,cur,ans=0;
    cin>>n;
    ll a[n];
    for(i=0;i<n;i++)
        cin>>a[i];
        cur=a[0];
    for(i=0;i<n-1;i++)
    {
        if(cur<a[i+1])
            continue;
        else
        {
            ans++;
            cur=a[i+1];

        }
    }
    cout<<++ans<<endl;

}















int main()
{
  // freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    run
    ll t;
    t=1;
  //cin>>t;
    while(t--){

    oka();
    }



}
