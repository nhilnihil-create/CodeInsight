#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std ;
int N;
int main(){
    cin >> N;
    string S;
    cin >> S;
    int count=0;
    for(int i=0;i<N-2;i++){
        if(S[i]=='A'&&S[i+1]=='B'&&S[i+2]=='C'){
            count++;
        }
    }
    cout << count << "\n";
}