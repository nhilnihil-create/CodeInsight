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
    int N;
    cin >> N;
    //cout << N/1000.0 << endl;
    //cout << N-1000*(N/1000.0) << endl;
    if(N%1000 == 0){
        cout << 0 << endl;
    }
    else{
        cout << 1000-N%1000 << endl;
    }
    return 0;
}