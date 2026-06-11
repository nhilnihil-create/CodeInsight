#include<bits/stdc++.h>
#define dbug printf("I am here\n");
#define Fast ios_base::sync_with_stdio(false); cin.tie(0);
#define vs             v.size()
#define ss             s.size()
#define sot(v)       sort(v.begin(),v.end())
#define rev(v)       reverse(v.begin(),v.end())
#define pii             pair<int,int>
#define ll               long long
#define ull             unsigned long long
#define pb             push_back
#define mpp          make_pair
#define Okay         0


static ll int inf = 1e18;
using namespace std;
void solve(){
    int n;
    cin>>n;
   ll int ar[n+5];
    for(int i = 0; i<n; i++){
        cin>>ar[i];
    }
    ll int ans = 1000;
    for(int i=1; i<n; i++){
        if(ar[i-1] < ar[i]){
            ans = (ans/ar[i-1])*ar[i] + (ans%ar[i-1]);
        }
    }
    cout<<ans<<endl;
}


int main(){

    Fast;
    solve();

    return Okay ;
}
