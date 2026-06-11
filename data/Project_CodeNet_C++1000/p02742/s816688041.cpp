#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;
using Vec = vector<int>;


int main() {

ll H,W;
 cin >> H >> W;

if(H == 1 || W == 1){
cout << 1 << endl;
} 
else {
 cout << (H * W + 1) / 2 << endl;
 }

 
}