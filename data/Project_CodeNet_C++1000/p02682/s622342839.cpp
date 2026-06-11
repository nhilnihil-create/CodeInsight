#include <bits/stdc++.h>
using namespace std;
int main(void){
    int A,B,C,K;
    cin >> A >> B >> C >>K;
    int64_t ans=0;
    if(K>=A) {
        ans+=A;
        K-=A;
    }
    else {
        ans=K;
        K=0;
    }
    
    if(K>=B) {
        K-=B;
    }
    else {
        K=0;
    }
    if(K>=C) {
        ans-=C;
    }
    else {
        ans-=K;
    }
  
    cout << ans << endl;
    
}
