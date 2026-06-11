#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
    long n;
    string s;
    cin >> n;
    while(n>0){
        n--;
        s += 'a'+n%26;
        n = (n-n%26)/26;
    }
    reverse(s.begin(),s.end());
    cout << s << endl;
}