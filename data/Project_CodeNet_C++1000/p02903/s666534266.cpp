#include <bits/stdc++.h>
using namespace std;

int main(){
    int h, w, a, b;
    cin >> h >> w >> a >> b;
    vector<vector<int>> s(h, vector<int>(w, 0));


    for(int i = 0; i < b; i++){
        for(int j = a; j < w; j++){
            s.at(i).at(j) = 1;
        }
    }

    for(int i = b; i < h; i++){
        for(int j = 0; j < a; j++){
            s.at(i).at(j) = 1;
        }
    }

    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cout << s.at(i).at(j);
        }
        cout << "" << endl;
    }

}