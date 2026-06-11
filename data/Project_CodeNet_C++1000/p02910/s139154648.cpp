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
    for(int i = 0 ; i<S.size(); i++){
        if( (i+1)%2 == 0 ){
           if( S[i]=='L' || S[i] == 'U' || S[i] == 'D' ){

           }else{
                cout << "No" << endl;
                return 0;
           }
        }else{
           if( S[i]=='R' || S[i] == 'U' || S[i] == 'D' ){

           }else{
                cout << "No" << endl;
                return 0;
           }

        }
    }
    cout << "Yes" << endl;
}
