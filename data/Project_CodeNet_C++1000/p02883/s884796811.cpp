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
typedef long long ll;
using namespace std;

template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}

ll A[200200],F[200200];
int n;
ll k;

bool isOK(ll x){
    ll rep = 0;
    for(int i=0;i<n;i++) rep += max((ll)0, A[i] - x/F[i]);
    if(rep <= k) return true;
    else return false;
}

int main(){
    cin.tie(0);ios::sync_with_stdio(false);
    cin >> n >> k;
    for(int i=0;i<n;i++) cin >> A[i];
    for(int i=0;i<n;i++) cin >> F[i];
    sort(A,A+n);
    sort(F,F+n,greater<>());

    ll ok = 100100100100100100;
    ll ng = -1;
    while(abs(ok - ng) > 1){
        ll mid = (ok + ng) / 2;
        if(isOK(mid)) ok = mid;
        else ng = mid;
    }
    cout << ok << endl;
    return 0;
}