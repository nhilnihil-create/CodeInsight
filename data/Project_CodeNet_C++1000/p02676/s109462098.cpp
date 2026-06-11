#include <bits/stdc++.h>
using namespace std;
int main(){
    long long i, k;
    string s;
    cin >> k;
    cin >> s;
    for(i=0;i<k;i++){
        if(i>=s.size()) break;
        cout << s[i] ;
    }
    if(s.size()>k) cout << "...";
    cout <<endl;
    return 0;
}

