#include<bits/stdc++.h>
using namespace std;

#define LL long long

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    char c[4]; cin >> c;
    for(int i = 1; i < 4; i++) if(c[i] == c[i-1]) return cout << "Bad", 0;
    cout << "Good";    
}