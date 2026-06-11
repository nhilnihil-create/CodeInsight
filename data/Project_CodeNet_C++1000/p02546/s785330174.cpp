#include <iostream>
#include <string>
using namespace std;



int main(){
    string S;
    cin >> S;
    int index;
    index = S.size() - 1;

    if (S[index] == 's'){
        S += "es";
    } else{
        S += 's';
    }

    cout << S << endl;

}
