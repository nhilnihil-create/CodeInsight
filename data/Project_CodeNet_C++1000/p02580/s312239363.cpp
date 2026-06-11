#include<bits/stdc++.h> 
using namespace std; 
 
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
#define lli long long int
#define ld long double
#define pb push_back
#define pf push_front
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define pll pair<lli,lli>
#define ve vector<lli>
#define vep vector<pair<lli,lli> >
#define fr(i,a,n) for(lli i=a;i<(n);i++)
#define frj(j,a,n) for(lli j=a;j<(n);j++)
#define frx(i,a,n) for(lli i=a;i>(n);i--)
#define frxj(j,a,n) for(lli j=a;j>(n);j--)
#define lb lower_bound
#define ub upper_bound
#define F first
#define S second
#define endl '\n'
#define db(x) cout << "[ " << x << " ]" << endl;
#define dbarr(arr,a,n) {fr(i,0,n) cout<<arr[i]<<" "; cout<<endl;}

int main(){
    lli h,w,m;
    cin>>h>>w>>m;
    map<lli,lli> cols,rows;
    map<pll,lli> pts;
    fr(i,0,m){
        lli x,y;
        cin>>x>>y;
        rows[x]++;
        cols[y]++;
        pts[mp(x,y)]++;
    }
    lli ans=0;
    lli maxi=-1e18;
    ve maxrows,maxcols;
    for(auto p:rows) maxi=max(maxi,p.S);
    for(auto p:rows){
        if(p.S==maxi)maxrows.pb(p.F);
    }
    ans+=maxi;
    maxi=-1e18;
    for(auto p:cols) maxi=max(maxi,p.S);
    for(auto p:cols){
        if(p.S==maxi)maxcols.pb(p.F);
    }
    ans+=maxi;
    lli flag=0;
    for(auto r:maxrows){
        for(auto c:maxcols){
            if(pts[mp(r,c)]==0){
                flag=1;
                break;
            }
        }
    }
    if(!flag)ans-=1;
    cout<<ans;
}