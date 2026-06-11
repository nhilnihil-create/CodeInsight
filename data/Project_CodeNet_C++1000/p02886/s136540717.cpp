#include<bits/stdc++.h>
#define ll      long long int
#define nl      '\n'
using namespace std;

int main(void){

    int n,m,ans=0;
        cin>>n;

    vector<ll>a(n+5);

    for(int i=1; i<=n; i++){
        cin>>a[i];
    }

    for(int i=1; i<=n; i++){
        for(int j=i+1; j<=n; j++){
            ans +=a[i]*a[j];
        }
    }
    cout<<ans;
}

