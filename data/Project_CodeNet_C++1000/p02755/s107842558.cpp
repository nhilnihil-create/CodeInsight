#include <iostream>
using namespace std;
int main(void){
    int a,b; 
    cin >> a >> b;
    int ans = -1;
    for(int i = 1 ; i <= 1000 ; i++){
        if(int(i * 0.08) == a && int(i * 0.1) == b){
            ans = i;
            break;
        }
    }
    cout << ans;
    
}
