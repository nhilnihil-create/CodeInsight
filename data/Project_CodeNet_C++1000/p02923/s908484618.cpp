#include <bits/stdc++.h>
#define ll long long
#define pi 3.14159265358979
#define mod 1000000007
#define rep(i,n) for(ll i=0;i<n;i++)
using namespace std;
const int INF = 1000100100;

int main(){
    ll n,a[200005],cnt=0,sum=0;
    cin>>n;
    rep(i,n){
        cin>>a[i];
        if(i>0){
            if(a[i]<=a[i-1]){
                cnt++;
                if(sum<cnt){
                    sum=cnt;
                }
            }else{
                cnt=0;
            }
        }
    }
    cout<<sum;
}