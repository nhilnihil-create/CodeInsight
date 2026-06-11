#include<iostream>
using namespace std;

int main(){
    int A;
    int B;

    cin >> A;
    cin >> B;

    int tap = 0;
    int sum = 1;
    while(sum < B ){
        sum += A - 1;
        tap++;

    }

    cout << tap << endl;
}