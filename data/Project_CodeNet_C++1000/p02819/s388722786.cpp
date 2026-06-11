#include <iostream>
#include <set>
using namespace std;
typedef long long ll;
const ll MAX = 100010;
set<int> st{};
int main(){
    ll x;
    cin >> x;
    // get all prime numbers so far
    for (int i=2; i<x; i++) {
        bool prime = true;
        for (auto itr=st.begin(); itr != st.end(); itr++){
            if (i % *itr == 0) {
                prime = false;
                break;
            }
        }
        if (prime) st.insert(i);
    }
    for (int n=x; n<MAX; n++){
        bool prime = true;
        for (auto itr=st.begin(); itr != st.end(); itr++){
            if (n % *itr == 0) {
                prime = false;
                break;
            }
        }
        if (prime) {
            cout << n << endl;
            return 0;
        }
    }
}