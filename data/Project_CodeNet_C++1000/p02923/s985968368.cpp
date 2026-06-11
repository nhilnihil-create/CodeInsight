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

void solve(){
    int n;
    cin >> n;
    vi h(n);
    REP(i,n) cin >> h[i];
    int ans = 0;
    for(int i = 0, j = 0; i < n ; i = j){
        int count = 0;
        for( j = i + 1 ; j < n ; j++){
            if( h[j] > h[j-1]) break;
            count++; 
        }
        if( count > ans) ans = count;
    } 
    cout << ans << "\n";
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