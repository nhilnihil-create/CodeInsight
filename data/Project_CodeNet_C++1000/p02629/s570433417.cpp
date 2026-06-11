#include <bits/stdc++.h>
using namespace std;

    int main() {
        
        long long n;
        cin >> n;
        
        string s = "";
        
        while(n--){
            
            int b = n%26;
            char c = 'a' + char(b);
            s+=c;
            n/=26;
            
            }
        
        reverse(s.begin(),s.end());
        cout << s;
        return 0;
        }