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
    char c;
    int i=0,flag=1;
    while(cin>>c){
        ++i;
        if((i&1 && c=='L') || ((i&1)==0 && c=='R')){
            //cout<<i;
            flag=0;
            break;
        }
    }
    if(flag) cout<<"Yes";
    else cout<<"No";
    return 0;
}