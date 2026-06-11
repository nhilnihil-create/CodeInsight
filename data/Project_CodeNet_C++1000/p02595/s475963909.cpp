#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)


int main(){
    double N,D;
    int count;
    count = 0;

    cin >> N  >> D;
    vector<vector<int>> hole(N,vector<int>(2));

    rep(i,N){
        cin >> hole.at(i).at(0);
        cin >> hole.at(i).at(1);  
    }

    rep(i,N){
        double A = hole.at(i).at(0);
        double B = hole.at(i).at(1);  
        if( (A*A) + (B*B) <= D*D ){
            count += 1;
        }
    }
    cout << count;

}