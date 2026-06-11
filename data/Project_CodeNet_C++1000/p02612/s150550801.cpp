#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lld long double
#define w(x) ll x;cin>>x;while(x--)
#define mod 1000000007
#define speed ios_base::sync_with_stdio(false);cin.tie(0);
using namespace std;

int main(){
    speed;
    int n;  cin>>n;
    int x=0;
    while(x<n){
        x+=1000;
    }
    cout<<x-n<<'\n';
    return 0;
}