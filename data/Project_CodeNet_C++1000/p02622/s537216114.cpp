#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;


const int MAX = 150001;  
int main(){
    string s, t;
    cin >> s >> t;
    int ans = 0;
    for (int i = 0; i < s.size(); ++i){
        if (s[i] != t[i]) ans++;
    }
    cout << ans;
}