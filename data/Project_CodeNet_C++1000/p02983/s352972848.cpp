#include <bits/stdc++.h>
#define ll long long
#define pi 3.14159265358979
#define mod 1000000007
#define rep(i,n) for(ll i=0;i<n;i++)
using namespace std;
const int INF = 1000100100;

int main(){
    ll n,m,p,q,t,min=INF;
    cin>>n>>m;
    p=n%2019;
    q=m%2019;  
    if(m-n>=2019||p>=q){
        cout<<0;
    }else{
        for(int i=p;i<=q-1;i++){
            for(int j=i+1;j<=q;j++){
                t=(i*j)%2019;
                if(min>t){
                    min=t;
                }
            }
        }
        cout<<min;
    }
}