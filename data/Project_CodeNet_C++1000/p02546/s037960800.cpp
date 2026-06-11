//vяпay
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define flash ios::sync_with_stdio(false);cin.tie(0);
const int mod = 1e9+7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    //string p = 'es';
    //string q = 's';
    if(s[s.size()-1] == 's'){
      cout << s << "es" << endl;
    }
    else
      cout << s << "s" << endl; 
    return 0;
}
