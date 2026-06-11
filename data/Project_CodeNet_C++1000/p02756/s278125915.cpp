#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include <queue>
#include <algorithm>
#include <deque>
using namespace std;
int min(int a,int b){
    return a<b?a:b;
}
int main(void){
    string S;
    int Q;
    bool right_reading = true;
    deque<char> dq;

    cin >> S >> Q;
    
    for(int i=0;i<S.length();i++){
        dq.push_back(S[i]);
    }
    for(int i=0;i<Q;i++){
        int T,F;
        char C;
        cin >> T;
        if(T == 1){
            right_reading = !right_reading;
        }
        else{
            cin >> F >> C;
            if((right_reading && F == 1)|| (!right_reading && F == 2)){
                dq.push_front(C);
            }
            else {
                dq.push_back(C);
            }
        }
    }
    
    if(right_reading){
        while(!dq.empty()){
            cout << dq.front();
            dq.pop_front();
        }
    }
    else{
        while(!dq.empty()){
            cout << dq.back();
            dq.pop_back();
        }
    }
}
