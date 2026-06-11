#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;
int solve(void){
    int N;
    string S;
    unordered_map<string,int> table;
    cin >> N >> S;
    int ans = 0;
    for(int num=0;num<=999;num++){
        string key = "";
        if(num < 10){
            key = "00";
        }
        else if(num < 100){
            key = "0";
        }
        key += to_string(num);
        int m = 0;
        bool OK;
        for(int i=0;i<3;i++){
            OK = false;
            for(int j=m;j<N;j++){
                if(S[m] == key[i]){
                    OK = true;
                    m++;
                    break;
                }
                m++;
            }
        }
        if(OK)ans++;
        
    }
    return ans;
    
}
int main(void){
    
    int ans = solve();
    cout << ans << endl;
}
