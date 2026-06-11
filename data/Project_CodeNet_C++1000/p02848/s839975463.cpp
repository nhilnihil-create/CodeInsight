#include <bits/stdc++.h>
using namespace std;

int main(void){
    
    int N;
    string S;
    cin >> N >> S;
    int len = S.size();
   
    for(int i=0;i<len;i++){
        S[i] = (char)S[i] + N;
        if((int)S[i] > 90) S[i] = (char)S[i] - 26;
    }
    
    cout << S << endl;
}
