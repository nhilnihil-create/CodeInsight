#include<bits/stdc++.h>
using namespace std;
int main(){
    string S;
    cin >> S;
    int length = S.size();
    if(S.at(length - 1) == 's'){
        cout << S << "es" << endl;
    }
    else{
        cout << S << 's' << endl;
    }
    return 0;
}