#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    string s;
    cin >> n;
    cin >> s;
    if(n%2 != 0){
        cout << "No" << endl;
        return 0;
    }
    for(int i=0; i<s.size()/2; i++){
        if(s.at(i) != s.at(i+s.size()/2)){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
}