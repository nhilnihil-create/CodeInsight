
//(・ω・)
#include <stdio.h>
#include <iostream> // cout, endl, cin
#include <string> // string, to_string, atoi
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
#include <iomanip> //setprecision
#include <limits>
#include <sstream> //istringstream
#include <stdlib.h>
#include <list>
#include <iterator>//std::advance()
using namespace std;
int main(){
    string s;
    cin >> s;
    if(s[0]=='M') cout << 6 << endl;
    else if(s[0]=='W') cout << 4 << endl;
    else if(s[0]=='F') cout << 2 << endl;
    else if(s[1]=='A') cout << 1 << endl;
    else if(s[1]=='H') cout << 3 << endl;
    else if(s[0]=='T') cout << 5 << endl;
    else cout << 7 << endl;
}
