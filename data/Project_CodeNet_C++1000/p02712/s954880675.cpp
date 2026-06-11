#include<bits/stdc++.h> 
using namespace std;
using ll = long long;

#define fast_io ios_base::sync_with_stdio(false) ; cin.tie(0); cout.tie(0);

int main() {
    fast_io;
    long long n;
    cin>>n;

    long long ans=0;
    for(int i=1;i<=n;i++) {
        if(i%3!=0&&i%5!=0&&i%15!=0) {
            ans+=i;
        }
    }
    cout<<ans<<endl;
}


