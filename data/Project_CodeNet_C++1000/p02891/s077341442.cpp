#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <random>
#include <cmath>
#include <iomanip>
#include <climits>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
#include <deque>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <list>
#include <unordered_map>
#include <bitset>
#include <sstream>

typedef  long long ll;
#define mop 1000000007
using namespace std;

int main() {
   
    string s;
    cin >> s;
    ll k;
    cin >> k;
    set <char> memo;
    for(ll i=0;i<s.length();i++){
        memo.insert(s[i]);
    }
    
    if(memo.size() == 1){
        cout << s.length()*k/2 << endl;
    }else{
        char state = 'X';
        ll ans1 = 0;
        for(ll i=0;i<s.length();i++){
            if(s[i] == state){
                ans1++;
                state = 'X';
            }else {
                state = s[i];
            }
        }
        ll ans2 = 0;
        string t;
        t = s+s;
        state = 'X';
        for(ll i=0;i<t.length();i++){
            if(t[i] == state){
                ans2++;
                state = 'X';
            }else {
                state = t[i];
            }
        }
//        cout << ans1 << " " << ans2 << endl;
        cout << ans1 + (k-1) * (ans2 - ans1) << endl;
    }

}