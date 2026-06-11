#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <list>
#include <utility>
#include <tuple>
#include <cstdio>
#include <set>
#include <queue>
#include <stack>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <cctype>
#include <cmath>
#define _GLIBCXX_DEBUG
using namespace std;
const long long INF = 1LL << 60;
typedef long long ll;
int main() {
    ll N, K;
    cin >> N >> K;
    ll ans;
    if(N==0){
        ans = 0;
    }
    else if(N > 0){
        if(N%K==0){
            ans = 0;
        }
        else{
            while(N >= K){
                ll nN1,nN2,nN;
                nN1 = abs(N - K);
                nN2 = N % K;
                if(nN1 < nN2){
                    nN = nN1;
                }
                else{
                    nN = nN2;
                }
                N = nN;
            }
            ll N1;
            N1 = abs(N-K);
            if(N1 < N){
                N =N1;
            }
            ans = N;
        }
    }
    cout << ans << endl;
}