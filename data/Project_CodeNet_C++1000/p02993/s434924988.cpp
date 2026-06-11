#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 1010000000000000017LL;
const ll MOD = 1000000007LL;

#define REP(i, n) for(ll i = 0 ; i < n; i++)

//#define DEBUG(fmt, ...)
#define DEBUG(fmt, ...) fprintf(stderr, fmt "\n", ##__VA_ARGS__)

int main(){
    std::cout<<std::fixed<<std::setprecision(10);

    string S;
    cin >> S;

    for(int i = 1; i < S.size(); i++ ){
        if( S[i] == S[i-1] ){
            cout << "Bad" << endl;
            return 0;
        }
    }

    cout << "Good" << endl;
}
