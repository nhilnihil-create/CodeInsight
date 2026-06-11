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
    int n, q;
    ll k;
    cin >> n >> k >> q;
    vi rel_score(n);
    ll abs_score = 0;
    REP(i, q){
        int a;
        cin >> a;
        a--;
        rel_score[a]++;
        if( a != 0){
            abs_score--;
        }
    }
    
    REP(i, n){
        int score =  k + abs_score + (rel_score[i] - rel_score[0]);
        if( score > 0){
            cout << "Yes\n";
        }else{
            cout << "No\n";
        }
    }


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