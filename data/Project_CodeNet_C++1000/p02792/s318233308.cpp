#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int main(){
    int n;
    cin >> n;
    int len = to_string(n).length(), sum = 0;
    int pw_init = 1;
    for(int i = 0; i < len-1; i++) pw_init *= 10;
    for(int i = n; i > 0; i--){
        if(i % 10 == 0) continue;
        int pw = pw_init;
        // ex) 2011 -> 1xx2
        string s = to_string(i);
        for(int j = len; j > 1; j--){
            // ex) 1002
            int th = (s[s.length()-1] - '0') * pw + (s[0] - '0');
            // cout << "th: " << th << endl;
            sum += max(0, min((n-th+10)/10, pw/10));
            // cout << "sum: " << sum << endl;
            pw /= 10;
        }
        if(s[s.length()-1] == s[0]) sum += 1;
    }
    cout << sum;
    return 0;
}