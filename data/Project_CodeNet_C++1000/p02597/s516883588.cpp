#include <iostream>

using namespace std;
int n;
string s;
int main(){
    cin >> n >> s;
    s = "!" + s;
    int j = n , ans = 0;
    for (int i = 1; i <= n; i++){
        if (s[i] == 'W'){
            while (s[j] != 'R' && i < j) j--;
            if (i < j) {
                swap(s[i],s[j]);
                ans++;
            }
        }
        if (i >= j) break;
    }
    cout << ans;
    return 0;
}