#include<bits/stdc++.h>
typedef long long ll;
#define forin(in, n) for(int i=0; i<n; i++) cin>>in[i]
#define forout(out, n) for(int i=0; i<n; i++) cout<<out[i]<<endl;
using namespace std;

int main(){
    int ans=0;
    int K; cin>>K;
    for(int a=1; a<=K; a++){
        for(int b=1; b<=K; b++){
            for(int c=1; c<=K; c++){
                ans+=__gcd(a, (__gcd(b, c)));
            }
        }
    }
    cout<<ans<<endl;
}
