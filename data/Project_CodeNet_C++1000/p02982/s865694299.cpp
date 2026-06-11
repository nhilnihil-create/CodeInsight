#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)

int main() {
    int n, d; cin >> n >> d;
    vector<vector<int>> vec(n, vector<int>(d));
    rep(i, n)rep(j, d){
        cin >> vec.at(i).at(j);
    }
    int count = 0;
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            int sum = 0;
            for(int k = 0; k < d; k++){
                sum = sum + (vec.at(i).at(k) - vec.at(j).at(k)) * (vec.at(i).at(k) - vec.at(j).at(k));
            }
            double sque = sqrt(sum);
            for(int c = 0; c <= sque; c++){
                if(c == sque) count++;
            }
        }
    }
    cout << count << endl;

    return 0;
}