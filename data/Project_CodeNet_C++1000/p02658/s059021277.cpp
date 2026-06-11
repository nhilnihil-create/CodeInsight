#define _LIBCPP_DEBUG 0
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const long long INF = 1LL << 60;
ll MOD = 1e9+7;

int main() {

    ll N; cin>>N;
    ll sum=1;
    double sum2=1;
    for (int i = 0; i < N; ++i) {
        ll A; cin>>A;
        sum *= A;
        sum2 *= A;
    }
    if((sum > 1000000000000000000ll)||(sum2 > 1000000000000000000ll)){
        cout<<-1<<endl;
    }else cout<<sum<<endl;
}