#include <bits/stdc++.h>
using namespace std;
int main(void){
    int N;
    cin >> N;
    string S[N];
    int T[N];
    for(int i = 0; i < N;i++)cin >> S[i] >> T[i];
    
    string tar;
    cin >> tar;
    
    bool flag = false;
    int sum = 0;
    
    for(int i = 0; i< N;i++){
        
        if(flag)sum += T[i];
        if(tar==S[i])flag = true;
    }
    cout << sum <<endl;
}
