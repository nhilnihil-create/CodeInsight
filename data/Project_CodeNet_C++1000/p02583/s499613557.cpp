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
#include <stack>
#include <queue>
#define mod 1000000007
const long long INF = 1LL << 60;
using namespace std;
typedef long long ll;
typedef long double ld;
// a>b -> a==b;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
// a<b -> a==b;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

int main(void)
{
    ll N, i, j, k, L[101], ans=0;

    cin >> N;

    for(i=1; i<=N; i++){
        cin >> L[i];
    }

    if(N<3) cout << 0 << endl;

    else{
        for(i=1; i<=N-2; i++){
            for(j=i+1; j<=N-1; j++){
                for(k=j+1; k<=N; k++){
                    if(L[i]!=L[j] && L[i]!=L[k] && L[j]!=L[k] && 
                    L[i]+L[j]>L[k] && L[j]+L[k]>L[i] & L[k]+L[i]>L[j]){
                        ans++;
                    }
                }
            }
        }

        cout << ans << endl;
    }

    return 0;
}