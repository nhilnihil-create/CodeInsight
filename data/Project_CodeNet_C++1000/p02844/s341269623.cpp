#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

//#define int long long
//signed main(){
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    string s;
    cin >> n >> s;
    int cnt=0;
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            for(int k = 0; k < 10; k++) {
                int dig[3]={i,j,k};
                int m=0;
                for(int l = 0; l < n; l++) {
                    if(s[l] == '0'+dig[m]) m++;
                    if(m==3){
                        cnt++;
                        break;
                    }
                }
            }
        }
    }
    cout << cnt << "\n";
    return 0;
}