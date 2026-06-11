#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    long long int k;
    cin >> s >> k;

    int n = s.length();
    string s2 = s;
    long long int ans1 = 0, ans2 = 0;
    for(int i=0; i+1<n; i++){
        if(s[i] == s[i+1]){
            ans1 += 1;
            s[i+1] = '.';
        }
    }
    if(s2[n-1] == s2[0]){
        s2[0] = '.';
        ans2 += 1;
    }
    for(int i=0; i+1<n; i++){
        if(s2[i] == s2[i+1]){
            ans2 += 1;
            s2[i+1] = '.';
        }
    }
    long long int ans;
    if(s[n-1] != s[0]) ans = k * ans1;
    else if(s2[n-1] == '.') ans = (k/2) * (ans1 + ans2) + (k%2) * ans1;
    else ans = ans1 + (k-1) * ans2;
    
    cout << ans << endl;
    return 0;
}