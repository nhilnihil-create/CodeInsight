#include <bits/stdc++.h>
using namespace std;

//解説AC

int main(){
    string s;
    long long k;
    cin >> s >> k;
    int n = s.size();
    long long x = 0;
    for(int i = 0; i < n-1; i++){
        if(s[i] == s[i+1]){
            x++;
            i++;
        }
    }
    long long ans = x * k;

    if( count(s.begin(), s.end(), s[0]) == n){
        if(n % 2 == 1){
            ans = n * k / 2;
        }
    }else if(s[0] == s[n-1]){
        int i = 1;
        long long m = 2;
        while(s[i] == s[0]){
            m++;
            i++;
        }
        i = n -2;
        while(s[i] == s[0]){
            m++;
            i--;
        }
        if(m % 2 == 0){
            ans += k-1;
        }
    }
    cout << ans << endl;
    return 0;
}
