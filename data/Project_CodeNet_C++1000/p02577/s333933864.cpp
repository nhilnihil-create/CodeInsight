//BISMILLAH
#include <bits/stdc++.h>
using namespace std;
int main(){
    
    string s;
    int i;
    cin >> s;
    int sum = 0;
    int len = s.size();
    for(i = 0;i<len;i++){
        sum += (s[i] - '0');
    }
    if(sum % 9 == 0) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}