#include <bits/stdc++.h>
#define rep(i, n)	for(int i=0;i<(int)(n);i++)
using namespace std;

int main(){
    vector<vector<int>> a(3, vector<int>(3));
    int n, b;
    rep(i, 3){
        rep(j, 3){
            cin >> a[i][j];
        }
    }
    cin >> n;
    vector<vector<int>> bingo(3,vector<int>(3));
    rep(i, n){
        cin >> b;
        rep(j, 3){
            rep(k, 3){
                if(a[j][k]==b){
                    bingo[j][k] = 1;
                }
            }
        }
    }
    vector<int> r(3,0);
    vector<int> c(3,0);
    rep(i, 3){
        rep(j,3){
            if(bingo[j][i]==1)
                c.at(i)++;
        }
    }
    rep(i, 3){
        rep(j,3){
            if(bingo[i][j]==1)
                r.at(i)++;
        }
    }
    if(bingo[1][1]==1&&bingo[2][2]==1&&bingo[0][0]==1
        || bingo[0][2]==1&&bingo[1][1]==1&&bingo[2][0]==1){
            cout << "Yes" << endl;
            return 0;
        }

    rep(i, 3){
        if(r.at(i)==3||c.at(i)==3){
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}