#include <bits/stdc++.h>
#include <math.h>
using namespace std;
#include <string>


int main(){
    int ans;cin>>ans;
    bool isEnd = false;

    while(1){
        if(ans == 2){
            break;
        }else if(ans%2==0){
            ans++;
            continue;
        }

        for(int i=2;i<ans;i++){
            if(ans % i == 0) break;
            if(i == ans-1) isEnd = true;
            //cout << ans << endl;
        }
        
        if(isEnd) break;

        ans++;

        
    }

    cout << ans << endl;
}