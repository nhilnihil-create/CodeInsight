#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<vector<bool>> isexist_f(n, vector<bool>(10, false));
    vector<vector<bool>> isexist_b(n, vector<bool>(10, false));
    for(int i = 0; i+1 < n; i++){
        isexist_f[i][s[i]-'0'] = true;
        for(int j = 0; j < 10; j++){
            isexist_f[i+1][j] = isexist_f[i][j];
        }
    }
    for(int i = n-1; i > 0; i--){
        isexist_b[i][s[i]-'0'] = true;
        for(int j = 0; j < 10; j++){
            isexist_b[i-1][j] = isexist_b[i][j];
        }
    }

    map<int, int> ans;
    for(int i = 1; i+1 < n; i++){
        int coans = (s[i]-'0')*10;
        for(int j = 0; j < 10; j++){
            if(isexist_f[i-1][j]){
                coans += j*100;
                for(int k = 0; k < 10; k++){
                    if(isexist_b[i+1][k]){
                        ans[coans+k] = 1;
                    }
                }
                coans -= j*100;
            }
        }
    }

    cout << ans.size() << endl;
    return 0;
}