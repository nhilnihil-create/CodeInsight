#include <iostream>
using namespace std;

int main(){
    string S;
    string result = "Yes";
    cin >> S;

    for(int i=0; i<S.size(); i++){
        if(i%2==0){
            if(S[i]!='R' && S[i]!='U' && S[i]!='D'){
                result = "No";
            }
        }
        else{
            if(S[i]!='L' && S[i]!='U' && S[i]!='D'){
                result = "No";
            }
        }
    }

    cout << result << endl;
    return 0;
}