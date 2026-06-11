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
    vi b(n);
    REP(i,n) cin >> b[i];
    //clean b
  
    int sum = b[0];
    for(int i = 1 ; i < n - 1 ; i++){
        sum += min(b[i-1], b[i]);
    }
    sum += b[n-2];
    cout << sum << "\n";
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