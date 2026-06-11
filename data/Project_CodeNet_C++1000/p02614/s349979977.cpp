/**In the name of Allah, the Most Merciful, the Most Merciful.**/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define INF 9223372036854775806
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define PI 2*acos(0.0)
#define EPS 1e-9
ll max(ll a,ll b) {if(a>b) return a; else return b;}
ll min(ll a,ll b) {if(a<b) return a; else return b;}

int main()
{
    int n,m,k;
    cin>>n>>m>>k;

    string s[n];
    int tot=0;
    for(int i=0;i<n;i++){
        cin>>s[i];
        for(int j=0;j<m;j++){
            if(s[i][j]=='#') tot++;
        }
    }
    ll res=0;
    for(int mask1=0;mask1<(1<<n);mask1++){
        for(int mask2=0;mask2<(1<<m);mask2++){
            set< pair<int,int> > cnt;
            for(int i=0;i<n;i++){
                if(mask1&(1<<i)){
                    for(int j=0;j<m;j++){
                        if(s[i][j]=='#'){
                            cnt.insert(mp(i,j));
                        }
                    }
                }
            }
            for(int j=0;j<m;j++){
                if(mask2&(1<<j)){
                    for(int i=0;i<n;i++){
                        if(s[i][j]=='#'){
                            cnt.insert(mp(i,j));
                        }
                    }
                }
            }
            //cout<<mask1<<" "<<mask2<<" "<<cnt.size()<<" "<<k<<endl;
            if(tot-cnt.size()==k) res++;
        }
    }
    cout<<res<<endl;

    return 0;
}


