#include <iostream>
#include <vector> 
#include <cmath>
using namespace std;

#define int long long

signed main() {
    int n;
    cin >> n;
    string s = "abcdefghijklmnopqrstuvwxyz";

    string ans = "";
    while(n > 0) {
        int rem = n % 26;
        if(rem == 0) {
            ans.push_back('z');
            n = n / 26 - 1;
        } else {
            ans.push_back(s[rem - 1]);
            n /= 26; 
        }
    }
   
   for(int i = ans.size() - 1; i >= 0; i--) {
       cout << ans[i];
   }
   cout << endl;
   return 0;
}