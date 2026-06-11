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

    long long N;
    vector <long long> arr; 

    cin >> N;
    for(int i=0; i < N; ++i){
        long long tmp;
        cin >> tmp;
        arr.push_back(tmp);
    }
    long long sum = 0;
    long long max = arr[0];
    for(int i=1; i < N; ++i){
        if(max>arr[i]){
            sum += (max-arr[i]);
        }
        else{
            max = arr[i];
        }
    }
    cout << sum << endl;
    return 0;
}