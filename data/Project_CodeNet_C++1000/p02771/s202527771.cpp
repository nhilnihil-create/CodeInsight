#include<bits/stdc++.h>
using namespace std;

#define LL long long

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int a[3]; for(int &i : a) cin >> i;
    sort(a, a+3);
    if((a[1] == a[0] && a[0] != a[2]) || (a[1] == a[2] && a[0] != a[2])) cout << "Yes";
    else cout << "No";    
}