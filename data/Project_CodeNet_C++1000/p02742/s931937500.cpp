#include<bits/stdc++.h>
using namespace std;
int main() {
int64_t n, m;
cin >> n >> m;
if(min(n, m) ==1) cout << 1;
else
cout << (n*m + 1)/2;
}
