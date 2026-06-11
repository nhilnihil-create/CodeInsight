#include <iostream>
using namespace std;
int solve(void){
    int X;
    cin >> X;
    int Q = X / 100;
    int P = X % 100;
    
    int sum = 0;
    for(int i=0;i<Q;i++){
        if(sum + 5 <= P)sum+=5;
        else if(sum + 4 <= P)sum+=4;
        else if(sum + 3 <= P)sum+=3;
        else if(sum + 2 <= P)sum+=2;
        else if(sum + 1 <= P)sum+=1;
        
        if(sum == P)return 1;
    }
    return 0;
    
}
int main(void){
    
    int ans = solve();
    cout << ans << endl;
}
