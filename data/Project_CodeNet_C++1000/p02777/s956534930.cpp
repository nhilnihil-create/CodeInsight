#include<iostream>
#include<string>
using namespace std;

int main(){
    string S, T, U;
    int A, B;
    cin >> S >> T;
    cin >> A >> B;
    cin >> U;
    if (S==U){
        A-=1;
    }else if (T==U){
        B-=1;
    }

    char result[50];
    sprintf(result, "%d %d", A, B);
    cout << result << endl;
}