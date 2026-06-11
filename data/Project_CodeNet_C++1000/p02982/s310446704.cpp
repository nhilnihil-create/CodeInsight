#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int main() {
    IOS;
    int N, D;
    cin >> N >> D;
    vector<vector<int>> nd_vec(N, vector<int>(D));
    int cnt = 0;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < D; j++){
            int t;
            cin >> t;
            nd_vec.at(i).at(j) = t;
        }
    }
    for (int i = 0; i < N; i++){
        for (int ii = 0; ii < N; ii++){
            if(i == ii){
                continue;
            }
            int sum = 0;
            for (int j = 0; j < nd_vec.at(i).size(); j++){
                sum += pow((nd_vec.at(i).at(j) - nd_vec.at(ii).at(j)),2);
            }
            double d = sqrt(sum);
            int in = sqrt(sum);
            if(d == in){
                cnt++;
            }
        }
    }
    cout << cnt / 2<< endl;
}