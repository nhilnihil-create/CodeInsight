#include<iostream>
using namespace std;

int main(void){
    string S, T;
    cin >> S >> T;
    bool result{true};

    for(int i=0; i<S.size(); ++i){
        if(S[i]!=T[i]){
            result = false;
        }
    }
    if(result){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }

}
