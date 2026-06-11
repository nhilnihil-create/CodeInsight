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
constexpr int mxN = 1e5+4;
bool prime_bool[mxN+1];
vi prime_list;
void complete_prime(){
    for(int i = 0 ; i < mxN ; i++){
        prime_bool[i] = ( i % 2 == 0) ? false : true; 
    }
    prime_bool[2] = true;
    prime_list.push_back(2);
    int current_index = 0;
    for(int i = 3; i < mxN ; i++){
        if(prime_bool[i] == false){
            continue;
        }else{
            //found new prime
            prime_list.push_back(i);
            for(int j = 2 ; j <= mxN / i ; j++){
               prime_bool[i * j] = false; 
            }
        }
    }
}
void solve(){
    complete_prime();
    int x;
    cin >> x;
    auto it = lower_bound(prime_list.begin(), prime_list.end(), x);
    cout << *it;
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