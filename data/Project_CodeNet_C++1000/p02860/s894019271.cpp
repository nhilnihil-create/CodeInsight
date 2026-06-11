#include <iostream>
#include <string>
using namespace std;
int main(void){
    int N;
    string S;
    cin >> N >> S;
    
    if(N%2!=0){
        cout << "No";
        return 0;
    }
    
    if(S.substr(0,N/2)==S.substr(N/2)) cout << "Yes";
    
    else cout << "No";
    
    
    return 0;
    
}
