#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
const int maxn = 3000050;
using namespace std;
typedef long long ll;
int main(){
ll A, V;
cin >> A >> V;
ll B,W;
cin >> B >> W;
ll T;
cin >> T;
ll D=abs(A-B);
ll D2=(V-W)*T;
puts(D<=D2?"YES":"NO");
}