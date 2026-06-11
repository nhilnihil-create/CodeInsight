#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> a(N);
    for(auto &x: a){
        cin >> x;
    }
    int sum  = 0;
    for(int i = 0; i < N; i++){
        if((i+1) % 2 == 1){
            if(a.at(i) % 2 == 1){
                sum++;
            }
        }
    }
    cout << sum << endl;
}