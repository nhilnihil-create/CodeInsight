#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define inf 1000000000
#define IOS ios_base::sync_with_stdio(0);cin.tie(0)
#define meM(y,a) memset(y,a,sizeof y)
#define sC(a) scanf("%d",&a)
#define alL(a) a.begin(),a.end()
#define prinT(a,sz)  cout<<a[0];for(int i=1;i<sz;i++)cout<<" "<<a[i];cout<<endl
#define ranD srand(chrono::steady_clock::now().time_since_epoch().count());
typedef pair<int,int>pi;
typedef pair<ll,ll>pll;
//int fx[]={0,0,1,-1};
//int fy[]={1,-1,0,0};
//int gx[]={0,0,1,1,1,-1,-1,-1};
//int gy[]={1,-1,0,1,-1,0,1,-1};
const int N=100010;
vector<pi>v[20];
bool check(int num,int pos)
{
    return num&(1<<pos);
}
int main()
{
    IOS;
    int n;cin>>n;
    for(int i=1;i<=n;i++)
    {
        int m;cin>>m;
        for(int j=0;j<m;j++)
        {
            int a,b;cin>>a>>b;
            v[i].pb({a,b});
        }
    }
    int ans=0;
    for(int num=(1<<(n+1))-1;num>=0;num--)
    {
        bool f=true;
        for(int i=1;i<=n;i++)
        {
            if(check(num,i))
                for(int j=0;j<v[i].size();j++){
                    int person=v[i][j].ff;
                    if(check(num,person)!=v[i][j].ss)
                    {
//                        cout<<num<<" "<<person<<" "<<v[i][j].ss<<endl;
                        f=false;
                        break;
                    }
                }
            if(f==false)break;
        }

        if(f){
            int cnt=0;
            for(int i=1;i<=n;i++)
                if(num&(1<<i))cnt++;
            ans=max(ans,cnt);
        }
    }
    cout<<ans<<endl;
}






