#include<bits/stdc++.h>

#define _GLIBCXX_DEBUG
#define all(v) (v).begin(),(v).end()

using namespace std;

using ll=long long;
using pii=pair<int, int>;
using vi=vector<int>;

const ll LINF=1LL<<60;
const int INF=1<<29;
const ll MOD=1e9+7;

template <typename T>
vector<T> divisor(T n){
    vector<T> ret;
    for(T i=2; i*i<=n; i++){
        if(n%i == 0){
            if(i*i == n) ret.push_back(i);
            else{
                ret.push_back(i);
                ret.push_back(n/i);
            }
        }
    }
    if(n != 1) ret.push_back(n);
    return ret;
}


int main(){
    ll N; cin >> N;
    vector<ll> d1, d2;
    d1=divisor(N);
    d2=divisor(N-1);
    ll res=0;
    for(int i=0; i<(int)d1.size(); i++){
        ll num=N;
        while(num%d1[i] == 0){
            num/=d1[i];
        }
        if(num%d1[i] == 1) res++;
    }
    res+=(int)d2.size();
    cout << res << endl;
    return 0;
}