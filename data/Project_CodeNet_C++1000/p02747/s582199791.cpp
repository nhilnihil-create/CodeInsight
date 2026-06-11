#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll mod = 1e9+7;

int main(){
    string s;
    cin >> s;
    int n = s.size();

    bool flag = true;
    for(int i = 0; i < n; i+= 2){
        if(s[i] != 'h' || s[i+1] != 'i'){
            flag = false;
        }
    }
    if(flag) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}