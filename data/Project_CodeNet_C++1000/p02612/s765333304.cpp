#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N ;
    int ans=0;
    for(int i=0;i<100;i++){
        if(1000*i>=N) {
            ans=1000*i-N;
            break;}
        }
    
    cout << ans << endl;
    }

