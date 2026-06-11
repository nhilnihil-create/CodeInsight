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

    string N;
    cin >> N;
    int sum = 0;

    for(int i = 0; i < N.size(); ++i){
        int tmp = N[i] - '0';
        sum += tmp;
    }

    if(sum%9 == 0){
        cout << "Yes" <<endl;
    }
    else{
        cout << "No" << endl;
    }

    return 0;
}