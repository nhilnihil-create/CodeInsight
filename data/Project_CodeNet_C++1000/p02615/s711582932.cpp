#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<vector>
#include<utility>
#include<queue>
#include<deque>
#include<stack>
#include<set>
#include<map>
#include<bitset>
#include<string>
#define MOD 1000000007
#define enld endl
typedef long long ll;
using namespace std;

template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}

int main(){
    cin.tie(0);ios::sync_with_stdio(false);
    ll N; cin >> N;
    vector<ll> A(N);
    for(int i=0;i<N;i++) cin >> A[i];
    sort(A.rbegin(), A.rend());

    ll ans = 0;
    for(int i=0;i<N-1;i++){
        ans += A[(i+1)/2];
    }

    cout << ans << endl;
    return 0;
}