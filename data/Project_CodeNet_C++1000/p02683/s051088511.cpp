#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <deque>
using namespace std;
using Graph = vector<vector<int>>;

int main() {
    //input
    int n,m,x; cin >> n >> m >> x;
    vector<int> c(n);
    vector<vector<int>> a(n, vector<int>(m));

    for(int i = 0;i < n; i++) {
            cin >> c[i];
        for(int j = 0; j < m ; j++){
            cin >> a[i][j];
    }
    }

    //compute
    int cost = 0;
    int counter = 0;
    for(int i = 0;i < n; i++)cost += c[i];
    vector<int> r(m,0);

    for (int bit = 0; bit < (1<<n); ++bit) {
        int flag = 1;
        vector<int> skill(m,0);
        int tcost = 0;
        for (int i = 0; i < n; ++i) {
            if (bit & (1<<i)) { // 列挙に i が含まれるか
                tcost += c[i];
                for (int j = 0; j < m; ++j){
                    skill[j] += a[i][j];
                }
            }
        }

        for (int i = 0; i < m; ++i) {
            if(skill[i] < x){
                flag = 0;
                break;
            }
        }

        if(flag == 1){
                counter++;
                cost = min(cost,tcost);
        }
    }

    //output
    if(counter == 0){
        cout << -1 << endl;
    }else{
        cout << cost << endl;
    }
}