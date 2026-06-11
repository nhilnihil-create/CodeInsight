#include <iostream>
using namespace std;
int main(){
    string s;
    cin >> s;
    int n = s.size(), K = s.size();
    for(int i=0; i<n-1; i++){
        if(s[i]==s[i+1]){
            K--;
            i += 2;
        }
    }
    cout << K << endl;
    return 0;
}