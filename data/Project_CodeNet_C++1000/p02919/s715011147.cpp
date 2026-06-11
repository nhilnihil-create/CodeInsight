#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i, n) for(int i = 0; i < n; i++)
#define all(a) a.begin(), a.end()
#define P pair<int, int>
#define F first
#define S second
#define mod 1000000007
#define INF 4000000000000000000
int dx8[8]={-1,0,1,1,1,0,-1,-1};
int dy8[8]={1,1,1,0,-1,-1,-1,0};
int dx4[4]={-1,0,1,0};
int dy4[4]={0,-1,0,1};
int gcd(int a,int b){
    if(b==0)return a;
    return gcd(b,a%b);
}
int uni[100010];
int root(int a){
    if(uni[a]<0)return a;
    return uni[a]=root(uni[a]); 
}
bool connect(int a,int b){
    a=root(a);
    b=root(b);
    if(a==b)return false;
    if(uni[a]>uni[b]){
        swap(a,b);
    }
    uni[a]=uni[a]+uni[b];
    uni[b]=a;
    return true;
}
signed main(void){
    int n;cin>>n;
    int V[n+2];//1-index
    rep(i,n){
        int p;cin>>p;
        V[p]=i+1;
    }
    multiset<int>S;//indexの集合であることに注意
    S.insert(0);S.insert(0);
    S.insert(n+1);S.insert(n+1);
    int ans=0;
    for(int i=n;i>=1;i--){
        int now=V[i];
        multiset<int>::iterator right;;
        right=S.upper_bound(now);
        
        int r0=*right;
        right++;int r1=*right;
        right--;right--;
        int l0=*right;
        right--;
        int l1=*right;
        //cout<<r0<<' '<<r1<<' '<<l0<<' '<<l1<<endl;
        
        ans+=i*((l0-l1)*(r0-now)+(now-l0)*(r1-r0));
        S.insert(now);
    }
    cout<<ans<<endl;
}
        
