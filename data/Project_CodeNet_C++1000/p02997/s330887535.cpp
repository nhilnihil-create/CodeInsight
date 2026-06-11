#include<iostream>

using namespace std;

#define rep(i, n) for(int i = 0; i < n; i++)

int main(){
    int n, k;
    cin >> n >> k;
    int num = (n - 1) * (n - 2);
    num /= 2;
    if (k > num) {
        cout << -1 << endl;
        return 0;
    }
    


    // 辺の数
    int m = (n - 1) + (num - k);

    pair<int, int> p[m];
    for(int i = 1; i < n; i++){
        p[i-1].first = 1;
        p[i-1].second = i + 1;
    }
    
    int idx = n - 1;
    if (idx == m) {
        cout << m << endl;
        for(int l = 0; l < m; l++){
            cout << p[l].first << ' ' << p[l].second << endl;
        }
        return 0;
    }
    for(int i = 1; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            p[idx].first = i + 1;
            p[idx].second = j + 1;
            idx++;
            if (idx == m) {
                cout << m << endl;
                for(int l = 0; l < m; l++){
                    cout << p[l].first << ' ' << p[l].second << endl;
                }
                return 0;
            }
        }
    }
}