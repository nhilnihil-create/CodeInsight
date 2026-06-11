#include <bits/stdc++.h>
using namespace std;

//n
int main() {
    int matrix[3][3];
    map<int,pair<int,int>>map;
    for(int i = 0;i < 3;i++){
        for(int j = 0;j < 3;j++){
            cin >> matrix[i][j];
            map[matrix[i][j]] = pair<int,int>(i,j);
        }
    }
    int t;
    cin >> t;
    while (t--){
        int i;
        cin >> i;
        if(map.count(i) != 0){
            auto p = map[i];
            matrix[p.first][p.second] = -1;
        }
    }
    bool find = false;
    for(int i = 0;i < 3;i++){
        if(matrix[i][0] == -1 && matrix[i][1] == -1 && matrix[i][2] == -1)
            find = true;
        if(matrix[0][i] == -1 && matrix[1][i] == -1 && matrix[2][i] == -1)
            find = true;
    }
    if(matrix[0][0] == -1 && matrix[1][1] == -1 && matrix[2][2] == -1)
        find = true;
    if(matrix[0][2] == -1 && matrix[1][1] == -1 && matrix[2][0] == -1)
        find = true;
    if(find)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}