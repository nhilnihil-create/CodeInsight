#include<iostream>
#include<vector>
#include<algorithm>
typedef long long ll;

using namespace std;

int main(){
    ll N, K, x;   cin >> N >> K;
    ll cnt = 0;
    ll rev = 0;
    ll ans;
    const ll mod2 = 1000000007;
    std::vector<ll> v(N);
    for(int i=0; i<N; i++)  cin >> v[i];
    for(int i=0; i<N-1; i++){
        for(int j=i+1; j<N; j++){
            if(v[i] > v[j]) cnt++;
        }
    }
    std::sort(v.begin(),v.end(),std::greater<ll>());

    x = 0;
    for(int i=1; i<N; i++){
        if(v[i-1] > v[i]){
            rev += i;
            x = i;
        }else    rev += x;
    }
    ans = cnt*K + (K*(K-1)/2)%mod2 * rev;
    ans = ans%mod2;
    cout << ans;
}