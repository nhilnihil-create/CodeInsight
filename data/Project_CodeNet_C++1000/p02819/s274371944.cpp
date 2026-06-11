#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;

int main() {
    int t=1;
    //cin >> t;
    while(t--){
        ll n,i,j;
        cin >> n;
        int prime[100005];
        memset(prime,true,sizeof(prime));
        prime[0]=false;
        prime[1]=false;
        for(i=2;i*i<=100005;i++){
            if(prime[i]){
                for(j=i*i;j<=100005;j+=i){
                    prime[j]=false;
                }
            }
        }
        for(i=0;i<=100005;i++){
            if(prime[i] && i>=n){
                cout << i ;
                break;
            }
        }
    }
}