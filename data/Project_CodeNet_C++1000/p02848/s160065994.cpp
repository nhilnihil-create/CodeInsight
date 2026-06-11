#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    string s;
    cin >> n;
    cin >> s;
    vector <int> v(s.length());
    for(int i = 0; i < v.size(); i++){
        v[i]=s[i]-'A';
        v[i]+=n;
        v[i]%=26;
        cout << (char)(v[i]+'A');
    }
    cout << endl;
    return 0;
}