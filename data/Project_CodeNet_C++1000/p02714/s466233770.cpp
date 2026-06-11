#include <bits/stdc++.h>
#define ll long long 
using namespace std;

int main() {
    long long n;
    cin >> n;
    string s;
    cin >> s;
    long long r = 0, g = 0, b = 0;
    cin >> r >> g >> b;
    for(long long i = 0;i< n; i++){
        if(s[i] =='R')r++;
        else if(s[i] == 'G')g++;
        else b++;
    }
    long long k = 0;
    for(long long i = 0; i < n; i++){
        for(long long j = i + 1; j < n; j++){
            if(s[i] != s[j] && (2*j - i) < n){
                if(s[2*j - i] != s[j] && s[2*j - i] != s[i])
                    k++;
            }
        }
    }
   // cout << r << " " << g << "  " << b << " " << k << endl;
    cout << r*g*b - k << endl;
    return 0;
}