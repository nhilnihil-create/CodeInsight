#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll N;
    cin >> N;
    vector<ll> vec(N);
    for(int i = 0; i < N; i++){
        cin >> vec.at(i);
    }
    reverse(vec.begin(), vec.end());
    for(int i = 0; i < N-1; i++){
        if(vec.at(i) >= vec.at(i+1)) continue;
        else if(vec.at(i) == vec.at(i+1) -1){
            vec.at(i+1)--;
        }
        else{
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
}