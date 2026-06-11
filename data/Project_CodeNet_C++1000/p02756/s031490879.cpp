#include <bits/stdc++.h>
using namespace std;

#define ALL(v) v.begin(), v.end()
#define V vector
#define P pair
#define ld long double
#define ll long long

const int MOD =  1000000007;
const int IINF = INT_MAX;
const ll INF = 1LL << 60;


int main() {
    string s; cin >> s;
    int q; cin >> q;
    deque<char> deq;
    for(int i = 0; i < (int)s.size(); i++){
        deq.push_back(s[i]);
    }
    bool flip = false;
    for(int i = 0; i < q; i++){
        int t; cin >> t;
        if(t == 2){
            int f; cin >> f;
            char c; cin >> c;
            if(f == 1){
                if(f == 1 && flip) deq.push_back(c);
                else deq.push_front(c);
            }else{
                if(flip) deq.push_front(c);
                else deq.push_back(c);
            }
        }else{
            flip = !flip;
        }
    }

    if(flip) reverse(ALL(deq));
    while(!deq.empty()){
        char c = deq.front();
        deq.pop_front();
        cout << c;
    }
    cout << "\n";

    return 0;
}
