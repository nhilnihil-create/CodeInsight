#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    map<string, int> m;
    for(int i = 0; i < N; i++){
        string S;
        cin >> S;
        m[S]++;
    }

    int num = 0;
    for(auto value : m){
        auto v = value.second;
        num = max(num, v);
    }

    for(auto value : m){
        auto v = value.second;
        if(v == num){
            cout << value.first << endl;
        }
    }    
}