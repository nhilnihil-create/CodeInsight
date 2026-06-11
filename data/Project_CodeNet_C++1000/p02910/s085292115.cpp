#include<bits/stdc++.h>
using namespace std;

int main() {
    string S;
    cin >> S;
    for(int i=0;i<S.size();i++) {
        if(i%2==0) {
            if(S[i]=='L') {
              puts("No"); 
              return 0;
            }
        }
        else {
            if(S[i]=='R') {
              puts("No"); 
              return 0;
            }
        }
    }
    puts("Yes");
    return 0;
}
