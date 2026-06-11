#include <bits/stdc++.h>
//#define DEBUG
#define REP( i , nn ) for(int i = 0 ; i < (int) nn; i++)
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
template <class T>
void print_vect(std::vector<T> v){
    for(int i = 0 ; i < v .size(); i++) cout << v[i] << " ";
    cout << endl;
}

constexpr int mxN = 1e5;
bool dp[mxN];

void solve(){
    int x; 
    cin >> x;
    for(int i = 0 ; i < 6 ; i++){
        dp[100 + i] = true;
    }
    for(int i = 106 ; i <= x ; i++){
        for(int j = 0 ; j < 6 ; j++){
            int val = i - 100 - j;
            if(dp[val]){
                dp[i] = true;
                break;
            }
        }
    }
    cout << dp[x] << "\n";
} 

int main()
{
    //making data IO Fast
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    /****************************/

    #ifdef DEBUG
    int TEST_CASES = 2;
    while(TEST_CASES--){
    #endif // DEBBUG

    solve();

    #ifdef DEBUG
    }
    #endif // DEBUG
    
    return 0;
}

//Thanks to CSES problemset
// I am trained with this kind of problem