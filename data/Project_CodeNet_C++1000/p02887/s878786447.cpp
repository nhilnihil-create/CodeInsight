#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int n;
    string s;
    cin >> n >> s;
    int cnt = 0;
    char c = 'A';
    for(int i=0;i<n;i++){
        if(s.at(i) != c) cnt++;
        c = s.at(i);
    }
    cout << cnt << endl;
}