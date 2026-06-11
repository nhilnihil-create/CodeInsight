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
    int N, X, T;
    cin >> N >> X >> T;

    if(N%X ==0){
        cout << (N/X)*T << endl;
    }
    else{
        cout << ((N/X)+1)*T << endl;
    }
    return 0;
}