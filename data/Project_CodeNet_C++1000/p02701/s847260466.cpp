#include <bits/stdc++.h>
using namespace std;
int main(void){
    // Your code here!
    long long N;
    cin >> N;
    vector<string> S(N);
    
    for(int i=0;i<N;i++) cin >> S[i];
    
    sort(S.begin(),S.end());
    
    int count = 1;
    for(int i=0;i<N-1;i++){
        if(S[i]!=S[i+1]) count++;
        
    }
    cout << count;
    return 0;
    
}
