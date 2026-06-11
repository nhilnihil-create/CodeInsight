#include <bits/stdc++.h>
using namespace std;

int main(){
    int A,B; cin >> A >> B;
    int ans=-1;
    for(int i=1; i<1010; i++){
        if(floor(i*0.08)==A && floor(i*0.1)==B){
            ans=i;
            break;
        }
    }
    cout << ans << endl;
}
