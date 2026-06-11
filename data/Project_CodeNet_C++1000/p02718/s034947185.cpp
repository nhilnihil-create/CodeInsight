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
    int N, M;
    cin >> N >> M;
    vector<int> A(N);
    double sum = 0;
    REP(i, N){
        cin >> A[i];
        sum += A[i];
    }

    
    int res = 0;
    REP(i, N){
        if(double(A[i]) >= double(sum/4/M)){
            res++;
        }
    }
    if(res >= M){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
}