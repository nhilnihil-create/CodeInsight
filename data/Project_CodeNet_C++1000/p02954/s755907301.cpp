//
// Created on 2020/07/24.
//


#include <iostream> // cout, endl, cin
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
#include <ios>
#include <iomanip>
#include <numeric>

#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
typedef long long ll;
using namespace std;
const long long LINF =1e18;
const int INF = 1e9;


int main() {
    string s;
    cin>>s;
    vector<int>ans(s.size(),0);
    int odd_sum = 0;
    int even_sum = 0;
    char now = 'R';
    int last_index = 0;
    for (int i = 0; i < s.size(); ++i) {
        if(s[i] == now){
            if(i % 2 == 0) even_sum ++;else odd_sum ++;
        }else{
            if(now == 'R'){
                if(i % 2 == 0) swap(odd_sum,even_sum);
                ans[i - 1] += even_sum;
                ans[i] += odd_sum;
                last_index = i;
            }else{
                if(last_index % 2 != 0) swap(odd_sum,even_sum);
                ans[last_index - 1] += odd_sum;
                ans[last_index] += even_sum;
            }
            if(now == 'R')now = 'L';else now = 'R';
            odd_sum = 0;
            even_sum = 0;
            if(i % 2 == 0) even_sum ++;else odd_sum ++;
        }
    }
    if(last_index % 2 != 0) swap(odd_sum,even_sum);
    ans[last_index - 1] += odd_sum;
    ans[last_index] += even_sum;

    for (int j = 0; j < s.size() - 1; ++j) {
        cout<<ans[j]<<" ";
    }
    cout<<ans[s.size() - 1]<<endl;

    return 0;
}
