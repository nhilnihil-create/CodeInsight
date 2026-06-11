#include <bits/stdc++.h>
using namespace std;

int main(){
    int M,D;
    cin >>M>>D;
    
    if(M<4){
        cout << 0 << endl;
        return 0;
    }
    
    
    int ans=0;
    
    for(int i=22; i<=D; i++){
        if(i%10<2)continue;
        
        if((i%10)*(i/10) <= M)ans++;
        
    }
    cout << ans << endl;
    
    return 0;
}