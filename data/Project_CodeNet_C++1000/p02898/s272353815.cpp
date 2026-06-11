#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const int m=1e9+7;
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    fastio
    int n,k;
    cin>>n>>k;
    int cnt=0;
    while(n--){
        int a;
        cin>>a;
        if(a>=k) ++cnt;
    }
    cout<<cnt;
    return 0;
}