#include <bits/stdc++.h>
using namespace std;

int main() {
    string S;
    cin >> S;
    bool hi = true;
    if(S.length()%2==0){
        for(int i=1;i<S.length();i+=2){
            if(S[i-1]!='h'||S[i]!='i'){
                hi = false;
            }
        }
    }else{
        hi = false;
    }

    if(hi) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
