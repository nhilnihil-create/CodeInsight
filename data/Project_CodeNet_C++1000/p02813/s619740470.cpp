#include <bits/stdc++.h>
//#define DEBUG
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
template <class T>
void print_vect(std::vector<T> v){
    for(int i = 0 ; i < v .size(); i++) cout << v[i] << " ";
    cout << endl;
}
bool cmp_vec(vi& a, vi& b){
    for(int i = 0 ; i < a.size() ; i++){
        if( a[i] != b[i]){
            return false;
        }
    }
    return true;
}
void solve(){
    int n;
    cin >> n;
    vi p(n), q(n);
    for( int i = 0 ; i < n ; i++){
        cin >> p[i];
    }
    for( int i = 0 ; i < n ; i++){
        cin >> q[i];
    }
    vi r(n);
    for(int i = 1; i <= n ; i++){
        r[i - 1] = i;
    }
    int a = -1, b = -1;
    int index = 0;
    do{
        if( a < 0){
            if( cmp_vec(p, r)){
                a = index;
            }
        }
        if( b < 0){
            if(cmp_vec(q,r)){
                b = index;
            }
        }
        index++;
    }while(next_permutation(r.begin(), r.end()));
    cout << abs( a - b) << endl;
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