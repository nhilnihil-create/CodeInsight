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

int cal_cost(vi& a , int p){
    int ans = 0;
    for(const auto & num : a){
        ans += (num - p) * ( num - p);
    }
    return ans;
}

void solve(){
    int N;
    cin >> N;
    vi X(N);
    for(int i = 0 ; i< N ; i++){
        cin >> X[i];
    }
    int min_cost = 100 * 100 * 100;
    for(int p = 1 ; p <= 100 ; p++){
        int cost = cal_cost(X, p);
        if( cost < min_cost){
            min_cost = cost;
        }
    }
    cout << min_cost << endl;
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

