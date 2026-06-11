#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <iomanip>
#include <math.h>
#include <utility>
#include <vector>
#include <map>
#include <unordered_map>
#include <cstdlib>
#define div1 1000000007
const long long INF = 1LL << 60;
using namespace std;
using ll = long long;
// a>b -> a==b;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
// a<b -> a==b;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

template <class T> void swap(T& a, T& b) { T t = std::move(a); a = std::move(b); b = std::move(t); }

int main(void)
{
    ll N, K, i, j, A[2000], in=0, ex=0, ans;

    cin >> N >> K;

    for(i=0; i<=N-1; i++){
        cin >> A[i];
    }

    for(i=0; i<=N-2; i++){
        for(j=i+1; j<=N-1; j++){
            if(A[i] > A[j]){
                in++;
            }
        }
    }

    for(i=0; i<=N-1; i++){
        for(j=0; j<=N-1; j++){
            if(A[i] > A[j]){
                ex++;
            }
        }
    }

    ans = (in * K) % div1;
    ans += (K*(K-1)/2)%div1 * ex % div1;
    ans = ans % div1;
    cout << ans << endl;

    return 0;
}