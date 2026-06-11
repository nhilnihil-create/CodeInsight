#include <iostream>
using namespace std;
int main(void){
    bool ans;
    char N, W;
    cin >> N;
    cin >> W; 
    cin >> N >> W;
    ans = 0;
    if(N==W){
    }else{
        ans = 1;
    }
    cin >> N >> W;
    if(N==W){
    }else{
        ans = 1;
    }
    if(ans==1){
        cout << "No";
    }else{
        cout << "Yes";
    }
}