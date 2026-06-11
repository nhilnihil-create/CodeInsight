#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

#include <iostream> // cout, endl, cin
#include <iomanip>
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <cstdint> // int64_t, int*_t
#include <cstdio> // printf
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset> // bitset
#include <cctype> // isupper, islower, isdigit, toupper, tolower
#include <math.h>
using namespace std;

const long long MOD = 1000000007;

int main(){
    int N;
    cin >> N;
    vector<pair<int, int>> D(N);
    for(int i = 0; i < N; i++){
        int D1, D2;
        cin >> D1 >> D2;
        D.at(i).first = D1;
        D.at(i).second = D2;
    }
    
    for(int i = 0; i < N - 2; i++){
        if(D.at(i).first == D.at(i).second && D.at(i + 1).first == D.at(i + 1).second && D.at(i + 2).first == D.at(i + 2).second){
            cout << "Yes" <<endl;
            return 0;
        }
    }
    cout << "No" << endl;
}