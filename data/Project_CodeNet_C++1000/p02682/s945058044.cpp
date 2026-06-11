#include <bits/stdc++.h>
using namespace std;
int main(void){
    // Your code here!
    long long A,B,C,K;
    cin >> A >> B >> C >> K;
    
    int trial;
    int sum=0;
    
    trial = K;
    
    if(trial > A){
        for(int i=0;i<A;i++) sum += 1;
        trial = K - A;
        if(trial > B){
            trial = K - A - B;
            if(trial > C){
                for(int i=0;i<C;i++) sum -= 1;    
            }
            else if(trial <= C){
                for(int i=0;i<trial;i++) sum -= 1;
            }
        }
        else if(trial <= B){
        }
    }
    else if(trial <= A){
        for(int i=0;i<trial;i++) sum += 1;
    }
    
    cout << sum;
    
}