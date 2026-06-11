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
#include <iomanip>
using namespace std;
#define int long long

signed main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    string s;
    int k;
    cin >> s >> k;

    string t = s, u = s;
    int tcount = 0, ucount = 0;

    int n = s.size();
    int count = 1;
    int sum = 0;

    for(int i = 0;i < n-1;i ++){
        if(s.at(i) == s.at(i+1)){
            count ++;
        }else{
            sum += count / 2;
            count = 1;
        }
        if(i == n-2) sum += count / 2;
    }

    if(count == n){
        cout << (n * k) / 2 << endl;;
        return 0;
    }

    if(s.at(0) != s.at(n-1)){
        cout << sum * k << endl;
        return 0;
    }

    int countf = 1,countl = 1;
    
    for(int i = 0;;i ++){
        if(s.at(i) == s.at(i+1)){
            countf ++;
        }else{
            break;
        }
    }
    for(int i = n-1;;i --){
        if(s.at(i) == s.at(i-1)){
            countl ++;
        }else{
            break;
        }
    }

    cout << sum * k - ((countf / 2) +  (countl / 2) - ((countf + countl) / 2)) * (k-1) << endl;
}