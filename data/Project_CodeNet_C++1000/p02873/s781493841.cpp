#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;

    int n = s.length();
    vector<long long int> a(n+1);
    long long int count = 0;
    for(int i=0; i<n; i++){
        if(s[i] == '<') count += 1;
        else count = 0;

        a[i+1] = max(a[i+1], count);
    }
    count = 0;
    for(int i=n-1; i>=0; i--){
        if(s[i] == '>') count += 1;
        else count = 0;

        a[i] = max(a[i], count);
    }

    long long int ans = 0;
    for(int i=0; i<n+1; i++){
        ans += a[i];
    }
    cout << ans << endl;
    return 0;
}