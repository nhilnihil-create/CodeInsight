#include <bits/stdc++.h>
#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=(ll)(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=(ll)(b);i--)
#define ALL(x) (x).begin(),(x).end() 
#define SIZE(x) ((ll)(x).size())
#define MAX(x) *max_element(ALL(x))
#define MIN(x) *min_element(ALL(x))
#define INF 1000000000
using namespace std;
typedef long long ll;

int main() {
    int N;
    cin >> N;

    int A[N];
    int max1 = 0, max2 = 0;
    REP(i, N){
        cin >> A[i];
        if (A[i] > max2){
            max2 = A[i];
        }
        if (A[i] > max1){
            max2 = max1;
            max1 = A[i];
        }
    }

    REP(i, N){
        if(A[i] == max1){
            cout << max2 << endl;
        }
        else cout << max1 << endl;
    }
}