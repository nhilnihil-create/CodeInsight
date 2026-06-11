#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    char tmp=' ';
    int ans = 0;
    string s; cin >> s;
    for(int i=0; i<n; i++){
        char c = s[i];
        if (tmp != c){
            ans ++;
            tmp = c;
        }
    }
    cout << ans << endl;
}