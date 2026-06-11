#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); ++i )

using namespace std;
typedef long long ll;

int main(){
    int N;
    int K;
    cin >> N >> K;
    vector<ll> list(N+5);
    ll sum = 0;
    rep(i,N){
        ll tmp;
        cin >> tmp;
        list.push_back(tmp);
    }
    sort(list.begin(),list.end(),greater<ll>());
    for (int i = K; i < list.size(); i++){
        sum += list[i];
    }
    cout << sum << endl;
    return 0;
}