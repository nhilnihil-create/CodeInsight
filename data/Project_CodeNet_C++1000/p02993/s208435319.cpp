#include <iostream>
#include <string>
using namespace std;
int main(void){
    string S;
    cin >> S;
    string ans ="Good";
    for(int i=0;i+1<S.size();i++){
        if(S[i] == S[i+1]){
            ans = "Bad";
        }
    }
    cout << ans << endl;
}
