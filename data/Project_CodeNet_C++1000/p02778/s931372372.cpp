#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;
int min(int a,int b){
    return a<b?a:b;
}
int main(void){
    string S;
    cin >> S;
    for(int i=0;i<S.length();i++){
        S[i] = 'x';
    }
    cout << S << endl;
}
