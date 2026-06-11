#include<bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;

    long long ans=0;
    
    for(long long a = 1;a < N;a++){
        for(long long b = a;a*b < N;b++){
            if(a == b){
                ans++;
            }else{
                ans += 2;
            }
        }
    }

    cout << ans << endl;
}