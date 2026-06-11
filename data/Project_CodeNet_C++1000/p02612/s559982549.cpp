#include<iostream>

using namespace std;

int main(){
    int N, temp;
    cin >> N;

    temp = N % 1000;
    if (temp == 0){
        cout << 0;
        return 0;
    }
    else{
        cout << 1000 - temp;
    }
    return 0;
}