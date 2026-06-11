#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mxn= 5e5+5;
#define mod 1000000007
#define endl '\n'
void rishabh(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
int main() {
    ll n,m;
    cin>>n>>m;
    if(n==1||m==1){
        cout<<1;
        return 0;
    }
    ll temp=(n*m);
    if((temp)%2==1)cout<<(temp)/2+1;
    else cout<<(temp)/2;
}

