#include <bits/stdc++.h>
using namespace std;

int main() {
    int X,N; cin >> X >> N;
    vector<int> p(N);
    int now;
    for(int i=0; i<N; i++){
        cin >> p.at(i);
    }
    int len=max(X,100-X);
    int checks=0;
    int checkl=0;
    for(int i=0; i<len+1; i++){
        checks=0; checkl=0;
        for(int j=0; j<N; j++){
            if(X-i == p.at(j)){
                checks=1;
            }
            if(X+i == p.at(j)){
                checkl=1;
            }
        }
        if(checks==0){
            X=X-i;
            break;
        }
        if(checks!=0 && checkl==0){
            X=X+i;
            break;
        }

    }
    cout << X << endl;
    }