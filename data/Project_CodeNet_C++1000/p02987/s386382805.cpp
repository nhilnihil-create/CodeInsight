#include <iostream>
#include <string>
using namespace std;
int main(void){
    string S;
    cin >> S;
    char a,b;
    int count[2] = {0};
    for(int i=0;i<S.size();i++){
        if(i == 0){
            a = S[i];
            count[0]++;
            continue;
        }
        if(S[i] == a){
            count[0]++;
        }
        else{
            if(count[1] == 0){
                b = S[i];
                count[1]++;
            }
            else if(S[i] == b){
                count[1]++;
            }
        }
    }
    if(count[0] == 2 && count[1] == 2){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
}
