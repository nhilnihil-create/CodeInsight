#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int N;
    int count = 0;
    cin >> N;
    for(int i = 1; i < 10; i++){
        if(N%i == 0){
            if((N/i) /10 > 0){
                continue;
            }
            else count++;
        }
    }
    if(count > 0){
        cout << "Yes" << endl;
    }
    else cout << "No" << endl;
}