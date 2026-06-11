#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    //v[i]には2^i以上の値を入れる
    vector<int> v[31]; 
    //pow2[n]=2^nとなるような配列を用意する(2^30>10^9なので2^30まであれば良い)
    int pow2[31];
    pow2[0] = 1;
    for (int i=1; i<31; i++) {
        pow2[i] = pow2[i-1] * 2;
    }
    for (int i=0; i<n; i++) {
        int a;
        cin >> a;
        for (int j=0; j<31; j++) {
            if (a < pow2[j+1]) {
                v[j].push_back(a);
                break;
            }
        }
    }
    for (int i=30; i>=0; i--) {
        sort(v[i].begin(), v[i].end(), greater<>());
        while(v[i].size() > 0) {
            if (i > 0) {
                v[i-1].push_back((*v[i].begin())/2);
            }
            v[i].erase(v[i].begin());
            m--;
            if (m == 0) { //割引券の残り枚数m=0になったら二重ループを両方とも抜ける
                i = 0;
                break;
            }
        }
    }
    long long result = 0;
    for (int i=30; i>=0; i--) {
        for (int j=0; j<v[i].size(); j++) {
            result += v[i][j];
        }
    }
    cout << result << endl;
}