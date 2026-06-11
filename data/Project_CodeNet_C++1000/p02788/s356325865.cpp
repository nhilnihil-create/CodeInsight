#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int>pii;
#define MOD 1000000007
#define MAXN 200005
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define ll long long
#define pb push_back
#define f first
#define s second
#define debug(x) cout << "debug 1: " << x << "\n";
#define debug2(x, y) cout << "debug 2: " << x << " " << y << "\n";
#define debug3(x, y, z) cout << "debug 3: " << x << " " << y << " " << z << "\n";
int n;
ll d,a,x,h,ans;
ll c[MAXN];
vector<pii>ar;



int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>d>>a;

    for(int i=0;i<n;i++){
        cin>>x>>h;
        ar.pb({x,h});
    }
    sort(ar.begin(),ar.end());

    for(int i=0,j=0;i<n;i++){
        while(j<n && ar[j].f<=ar[i].f+2*d){
            j++;
        }

        ll best=max((ar[i].s-c[i]*a+a-1)/a,0ll);

         //debug3(i,j,best);
         //debug(c[i]);
        ans+=best;
        c[i]+=best;
        c[j]-=best;
        c[i+1]+=c[i];
    }

    cout<<ans;
    }