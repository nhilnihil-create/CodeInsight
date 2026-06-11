#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1000000007;
#define INF 1LL<<30
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()

int num[1000010];

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    rep(i,n){
        cin>>a[i];
        num[a[i]]++;
    }
    sort(all(a));
    vector<bool> ok(1000010,true);
    for(int i=1;i<1000010;i++){
        if(num[i]==0) continue;
        for(int j=i+i;j<1000010;j+=i){
            ok[j]=false;
        }
    }
    rep(i,n){
        if(num[a[i]]>1) ok[a[i]]=false;
    }

    int ans=0;
    rep(i,n){
        if(ok[a[i]]) ans++;
    }

    cout<<ans<<endl;
} 
