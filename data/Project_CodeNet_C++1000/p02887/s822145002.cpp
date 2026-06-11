#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std ;
int N;
int main(){
    cin >> N;
    string S;
    cin >> S;
    int An=N;
    for(int i=0;i<N-1;i++){
        if(S[i]==S[i+1]){
            An--;
        }
    }
    cout << An << "\n";
}