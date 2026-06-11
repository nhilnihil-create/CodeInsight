#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
const int INF = 1001001001;
const int MOD = 1000000007;
typedef long long ll;


int main(){
    int N;
    cin >> N;
    deque<ll> A;
    rep(i, N){
        ll ipt;
        cin >> ipt;
        A.push_back(ipt);
    }
    ll left = 0, right = 0;
    while(!A.empty()){
        if(left < right){
            ll num = A.front();
            left += num;
            A.pop_front();
        }else{
            ll num = A.back();
            right += num;
            A.pop_back();
        }
    }
    cout << abs(right - left) << endl;
    return 0;
}
