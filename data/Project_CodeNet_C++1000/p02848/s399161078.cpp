#include<bits/stdc++.h>
using namespace std;
 
int main(){
    int N;
    cin >> N;
    string S;
    cin >> S;
    for(int i=0;i<S.size();i++){
            S[i] = S[i] + N;
            if(S[i]>'Z'){
                S[i] = 64 + (S[i]-'Z');
            }
    }
    cout << S << endl;
    return 0;
}