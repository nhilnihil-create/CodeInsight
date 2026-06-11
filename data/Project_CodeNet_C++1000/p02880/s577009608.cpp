//Muhamad Syahreza Trihatmanto
#include <bits/stdc++.h>
using namespace std;

int N;
bool ada = false;

int main (){
    cin >> N;
    for(int r=1; r<=9; r++){
        for(int z=1; z<=9; z++){
            if(r*z == N){
                ada = true;
            }
        }
    }
    if(ada) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}