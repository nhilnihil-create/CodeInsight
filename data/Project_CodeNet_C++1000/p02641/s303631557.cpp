#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
using namespace std;


template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

int main(){
    int X, N;
    unordered_set<int> u_s;
    cin >> X >> N;
    for(int i = 0; i < N; ++i){
        int tmp;
        cin >> tmp;
        u_s.insert(tmp);
    }
    if(u_s.find(X) == u_s.end()){
        cout << X << endl;
        return 0;
    }
    int dif = 1;
    while(1){
        if(u_s.find(X-dif) == u_s.end()){
            cout << X-dif << endl;
            break;
        }

        if(u_s.find(X+dif) == u_s.end()){
            cout << X+dif<< endl;
            break;
        }
        ++dif;
    }

    return 0;
}