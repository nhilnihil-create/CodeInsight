#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<bool> isexist(1000, false);
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            for(int k = 0; k < 10; k++){
                int l = 0;
                for(; l < n;){
                    if(s[l++]-'0' == i) break;
                }
                for(; l < n;){
                    if(s[l++]-'0' == j) break;
                }
                for(; l < n; l++){
                    if(s[l]-'0' == k) break;
                }
                if(l < n) isexist[i*100+j*10+k] = true;
            }
        }
    }

    int ans = 0;
    for(int i = 0; i < 1000; i++){
        if(isexist[i]) ans++;
    }
    cout << ans << endl;
    return 0;
}