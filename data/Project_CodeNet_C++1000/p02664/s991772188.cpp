#include<bits/stdc++.h>
using namespace std;
int main(){
    string t;
    cin >> t;
    for(int i = 0; i < t.size(); i++){
        if(t[i] == '?')
            cout << 'D';
        else 
            cout << t[i];
    }
    return 0;
}