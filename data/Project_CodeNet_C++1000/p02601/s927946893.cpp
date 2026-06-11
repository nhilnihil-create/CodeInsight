#include <iostream>
#include <string>
using namespace std;
int main(void){
    int A, B, C, K;
    int cnt;
    string res;
    cin >> A >> B >> C;
    cin >> K;
    
    while(A >= B){
        B *= 2;
        cnt++;
    }
    
    while(B >= C){
        C *= 2;
        cnt++;
    }
    
    if(cnt <= K){
        res = "Yes";
    }else{
        res = "No";
    }
    
    cout << res;
    return 0;
}
