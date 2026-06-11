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

using namespace std;
 
int main(){
    int A;
    int count_1 = 0;
    int count_2 = 0;
    int B;
    cin >> A;
    for(int i = 1; i <= A; i++){ 
        count_1 = 9;
        B = i;
        while(true){
            if(B/10 > 0){
                B = B/10;
                count_1++;
            }
            else {
                B = B/10;
                break;
            }
        }
        if((count_1 % 2) == 1){
            count_2++;
        }
    }
    cout << count_2 << endl;
}