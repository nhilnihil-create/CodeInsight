# include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define pii pair<int,int>
typedef long long ll;
ll n,a,b,ans;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n;
    cin>>a>>b;
    if(a>b) swap(a,b);
    ans=min(b-1,n-a);
    if((b-a)%2==0){
        ans=min(ans,(b-a)/2);
    }    
    else{
        ans=min(ans,a+((b-a)-1) /2);
        ans=min(ans,n-b+1 +(n-(a+n-b+1)) /2);
    }
    cout<<ans<<endl;
}