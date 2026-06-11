#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main(){
    char c;
    cin >> c;
    char ans ;
    if('A' <= c && c <= 'Z') ans = 'A';
    else ans = 'a';
    cout << ans  << endl; 
    return 0;
}