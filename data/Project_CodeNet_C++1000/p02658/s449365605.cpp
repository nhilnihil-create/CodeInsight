#include <iostream>
#include <cmath>
using namespace std;
int main(void){
    
    long long num = pow(10, 18);
    unsigned long long sum = 1;
    
    
    int N;
    cin >> N;
    
    bool check = false;
    for(int i = 0; i < N; i++){
        long long A;
        cin >> A;
        if(A == 0){
            cout << 0 << endl;
            return 0;
        }
        
        // 10の18乗を超えるか判定
        if(sum > num / A || check == true){
            check = true;
        }
        
        sum *= A;
    }
    
    if(check == true){
        cout << -1 << endl;
    }
    else{
        cout << sum << endl;
    }
}
