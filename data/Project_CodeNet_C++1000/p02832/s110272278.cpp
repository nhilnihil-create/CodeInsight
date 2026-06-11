#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define INF 1e9+7
#define rep(i,n) for(ll i=0;i<n;i++)
const int maxn = 200000;
ll mod = INF;

int n;
int a[maxn];
bool key=false;
int ans;

int main(){
    
    cin >> n;
    rep(i,n){
        cin >> a[i];
    }
    ans=n;
    int now=0;
    rep(i,n){
        if(a[i]==now+1){
            now=a[i];
            ans--;
        }
    }

    if(ans==n){
        cout << -1<<endl;
    }else{
        cout << ans<<endl;
    }

    return 0;
}