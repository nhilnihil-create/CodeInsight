#include <iostream>
#include <cstdio>
using namespace std;

int main(){
    long long n;
    cin >> n;

    string s;
    cin >> s;
    string ans;

    for(long long i = 0; i < s.size(); i++){
        if(s[i] + n <= 'Z') ans.push_back(s[i] + n);
        else{
            long long delta = s[i] + n - 'Z' - 1;
            ans.push_back('A' + delta);
        }
    }

    cout << ans << endl;
    return 0;
}