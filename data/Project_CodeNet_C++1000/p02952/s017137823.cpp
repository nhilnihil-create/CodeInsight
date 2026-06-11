#include <bits/stdc++.h>
using namespace std;

int main(){
    int S;
    cin >> S;
    int A = S;

    int count = 0;

    for(int i = 1; i <= A; i++){
        if(i < 10){
            count++;
        }
        else if(i >= 100 && i < 1000){
            count++;
        }
        else if(i >= 10000 && i < 100000){
            count++;
        }
    }

    cout << count << endl;
}