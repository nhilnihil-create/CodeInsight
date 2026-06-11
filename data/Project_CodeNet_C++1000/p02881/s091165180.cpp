#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
    ll N; cin>>N;
    int n = (int)pow(N,0.5);
    int ans=1;
    for(int i=n; i>=1; i--){
        if(N%i==0){
            ans=i;
            break;
        }
    }
    cout<<(ans-1)+(N/ans)-1<<endl;
    return 0;
}