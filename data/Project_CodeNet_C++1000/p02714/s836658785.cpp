#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<char> v(n);
    int64_t c_r = 0;
    int64_t c_g = 0;
    int64_t c_b = 0;
    for(int i = 0; i < n;i++) {
        char c;
        cin >> c;
        if(c == 'R') c_r++;
        else if(c == 'G') c_g++;
        else if(c == 'B') c_b++;
        v.at(i) = c;
    }
    int64_t eq_c = 0;
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n;j++){
            int k = j + j - i;
            if(k >= n)continue;
            if(v.at(i) != v.at(j) && v.at(j) != v.at(k) && v.at(i) != v.at(k)) eq_c++;
        }
    }
    int64_t ans = c_r * c_b * c_g - eq_c;
    cout << ans << endl;
     
}