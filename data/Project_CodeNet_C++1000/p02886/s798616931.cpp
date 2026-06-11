#include <bits/stdc++.h>
using namespace std;

int main(void){
   
    int N,ans=0;
    cin >> N;
    int data[N];
    
    for(int i=0;i<N;i++) cin >> data[i];
    
    for(int i=0;i<N;i++){
        for(int j= i+1;j<N;j++){
            ans += (data[i] * data[j]);
        }
    }
    
    cout << ans << endl;
}