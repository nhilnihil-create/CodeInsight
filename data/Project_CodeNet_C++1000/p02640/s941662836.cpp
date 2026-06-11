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
    int kame, turu;
    int X, Y;

    cin >> X >>Y;
    //turu = Y-kame;
    if((Y-2*X)>=0 && (Y-2*X)%2 == 0){
        if((Y-2*X)/2 <= X){
            cout << "Yes" << endl;
        }
        else{
            cout << "No" << endl;
        }
    }
    else {
        cout << "No" << endl;
    }
    
    return 0;
}