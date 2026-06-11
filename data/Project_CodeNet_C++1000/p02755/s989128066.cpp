#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i <= (int)(n); i++)

int main() {
    int A,B;
    cin >> A >> B;
    int res=INT32_MAX;
    for(int i=1;i<1100;i++){
        if((int)(i*0.08)==A && (int)(i*0.1)==B){
            res=min(i,res);
        }
    }
    if(res==INT32_MAX)cout<<-1;
    else cout<<res;
    return 0;
}