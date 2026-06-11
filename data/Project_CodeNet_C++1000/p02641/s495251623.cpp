#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main (){
    int X, N;
    cin >> X >> N;
    vector<int> p(N);
    rep(i, N){
        cin >> p.at(i);
    }
    
    int num = X;
    bool flag;
    bool first = false;
    rep(i, N){
        if(num == p.at(i)){
            first = true;
        }
    }
    int count = 0;
    while(first){
        count ++;
        flag = false;
        num = X - count;
        rep(i, N){
            if(num == p.at(i)){
                flag = true;
                break;
            }
        }
        if(!flag){
            break;
        }

        flag = false;
        num = X + count;
        rep(i, N){
            if(num == p.at(i)){
                flag = true;
                break;
            }
        }
        if(!flag){
            break;
        }
    }
    cout << num << endl;
}