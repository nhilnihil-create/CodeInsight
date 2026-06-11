#include <bits/stdc++.h>
using namespace std;

int main(void){

    int N,ans=0;
    string S;
    cin >> N >> S;
    int len = S.size();
    
    for(int i=0;i<len-2;i++) if(S[i] == 'A' && S[i+1] == 'B' && S[i+2] == 'C') ans++;
    
    cout << ans << endl;
}