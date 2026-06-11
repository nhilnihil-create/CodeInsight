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
ll call(long long n){
    if(n==0)return 0;
    if(n==1)return 1;
    return 1 + 2*call(n/2);
}
int main(){
    ll n;
    cin>>n;
    cout<<call(n);
}

