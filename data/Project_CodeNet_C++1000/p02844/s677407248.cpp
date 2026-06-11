#include<bits/stdc++.h>
#include<string>
using namespace std;

int main(void){
    // Your code here!
    int n;
    cin >> n;
    
    string s;
    cin >> s;
    int ans = 0;
    for(int i=0;i<1000;i++){//000~999でsの中に3桁あるか探す
        string sum ="";
        if(i<10){
            sum += "00";
        }else if(i<100){
            sum += "0";
        }
        
        sum += to_string(i);
        
        int cu = 0;
        
        for(int j=0;j<n;j++){
            if(sum[cu] == s[j]){
                cu++;
            }
            if(cu == 3) break;
        }
        
        if(cu == 3) ans++;
    }
    
    
    cout << ans << endl;
}
