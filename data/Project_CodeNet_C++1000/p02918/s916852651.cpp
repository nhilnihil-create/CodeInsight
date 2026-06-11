#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

int main(){
    int n, k;
    string s;
    cin >> n >> k >> s;

    int dif = 0;
    for(int i = 0; i < n-1; i++){
        if (s[i] != s[i+1])dif++;
    }

    int aftdif;
    if (dif >= k*2)aftdif = dif - k*2;
    else aftdif = 0;
    int ans = n - 1 - aftdif;
    cout << ans << endl;
    return 0;
}