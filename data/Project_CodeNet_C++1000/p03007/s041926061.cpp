//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pp pair<int,int>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define ld long double
#define al(a) (a).begin(),(a).end()
#define mk make_pair
#define check cout<<"?"<<endl;

ll MOD=1000000007;
ll mod=998244353;
int inf=1000001000;
ll INF=1e18+5;

int main(){
    int n,P=0,N=0; cin>>n;
    vector<int> a(n,0);
    rep(i,n){
        cin>>a[i];
        if(a[i]>=0) P++;
        else N++;
    }
    sort(al(a)); reverse(al(a));
    if(N==n){
        N--; P++;
    }
    else if(P==n){
        N++; P--;
    }
    int ans=0;
    rep(i,n){
        if(i<P) ans+=a[i];
        else ans-=a[i];
    }
    cout<<ans<<endl;
    int cur=a[P];
    rep(i,P-1){
        cout<<cur<<" "<<a[i+1]<<endl;
        cur-=a[i+1];
    }
    cout<<a[0]<<" "<<cur<<endl;
    cur=a[0]-cur;
    rep(i,N-1){
        cout<<cur<<" "<<a[P+1+i]<<endl;
        cur-=a[P+1+i];
    }
}
