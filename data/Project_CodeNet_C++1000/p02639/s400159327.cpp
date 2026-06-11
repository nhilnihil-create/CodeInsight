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
    int ans = 0;
    //vector<int> arr(5);
    for(int i = 0; i < 5; ++i){
        int tmp;
        cin >> tmp;
        if(tmp == 0){
            ans = i+1;
        }
    }
    cout << ans << endl;
    return 0;
}