#include <iostream>
using namespace std;
int main(){
    int n,l;
    cin  >> n >> l;
    int ans = 0;
    int nnum = 101;
    bool flag = true;
    for(int i = 0; i < n; i++){
        ans += l+i;
        if(abs(l+i) < nnum){
            nnum = abs(l+i);
            if(l+i<0) flag = false; 
            else flag = true;
        }
    }
    if(flag)cout << ans-nnum << endl;
    else cout << ans+nnum << endl;
    return 0;
}