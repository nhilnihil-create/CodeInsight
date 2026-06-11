#include<bits/stdc++.h>

using namespace std;

int main(){
    int A,B,C,K,ans=0;
    cin >> A >> B >> C >> K;
    while(K>0){
        if(A>0){
            ans++;
            A--;
        }
        else if(B>0){
            B--;
        }
        else if(C>0){
            ans--;
            C--;
        }
        K--;
    }
    cout << ans << endl;
}