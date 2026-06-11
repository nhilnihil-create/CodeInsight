#include <iostream>
using namespace std;

#define rep(i,n) for(int i=0; i<(n); i++)

#include <string>
#include <vector>
#include <algorithm>
int main(){
    string str; cin >> str;
    for(int i=0; i<str.size(); i++){
        if(str[i] == ( ((i+1)%2) ?'L':'R')) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
}