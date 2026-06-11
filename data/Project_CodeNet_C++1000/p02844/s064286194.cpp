#include <bits/stdc++.h>

using namespace std;
using ll = long long;

//cout << std::fixed << std::setprecision(15) << y << endl;

int main() {
    int n = 0;
    string s = "";
    cin >> n >> s;
    vector<int> c(3);
    int sum = 0;
    
    for(int i = 0;i < 1000;i++){
        int tmp = i;
        c[2] = tmp % 10;
        tmp /= 10;
        c[1] = tmp % 10;
        c[0] = tmp / 10;
        int f = 0;
        
        for(int j = 0;j < n;j++){
            
            if(c[f] == s[j] - '0'){
                f++;
            }
            if(f == 3){
                break;
            }
           //cout << "hoge" << endl;
        }
        if(f == 3){
            sum ++;
        }
    }
    cout << sum << endl;
    return 0;
}