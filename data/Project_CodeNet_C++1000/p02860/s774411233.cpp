#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    if(n%2 != 0)cout << "No" <<endl;
    else{
        int p = n/2;
        bool pos = true;
        for(int i = 0 ; i < p ; i++){
            if(s[i] != s[i+p]){
                pos = false;
                break;
            }
        }
        if(pos)cout << "Yes" <<endl;
        else cout << "No" << endl;
    }
}
