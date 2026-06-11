#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define REP(i,n) for (ll i = 0; i < (n); ++i)
#define RREP(i, n) for (ll i = (n) - 1; i >= 0; --i)
#define ALL(v) (v).begin(), (v).end()
template<class T>
using reverse_priority_queue = priority_queue<T, vector<T>, greater<T>>;

const string YES = "Yes";
const string NO = "No";

int main(){
    string s;
    cin >> s;
    if(s.size() < 2 || s.size() % 2 == 1){
        cout << NO << endl;
        return 0;
    }
    REP(i, s.size()){
        if(i % 2 == 0){
            if(s.at(i) != 'h'){
                cout << NO << endl;
                return 0;
            }
        }else{
            if(s.at(i) != 'i'){
                cout << NO << endl;
                return 0;
            }
        }
    }
    cout << YES << endl;
    return 0;
}
