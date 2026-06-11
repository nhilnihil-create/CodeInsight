#include<bits/stdc++.h>

#define Bye return 0
#define ll long long

using namespace std;

void solve(){
    int k; cin>>k;
    int sum = 0;
    for (int i=1; i<=k; i++){
        for (int j=1; j<=k; j++){
            for (int x=1; x<=k; x++){
                int g = __gcd(i, j);
                sum += __gcd(g, x);
            }
        }
    }
    cout<<sum<<endl;
}

int main(){
    solve();
    Bye;
}