#include <iostream>
#include <string>
using namespace std;
int main(void){
    int N;
    cin >> N;
    int L = N*2;
    string S,T;
    cin >> S >> T;

    string U[L];

    int j=0,k=0;

    for(int i=0;i<L;i++){
        if(i==0||i%2==0) {
            cout << S[j];
            j++;
        }
        else{
            cout << T[k];
            k++;
        }
    }

    return 0;
 
}