#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include<algorithm>
#include<string>
#include <map>
#include <queue>
#include <stack>
#include<set>

#define DIV 1000000007

using namespace std;
using ll = long long;
using ldb = long double;
int main(){
 int N;
 ldb ans = 0.0, a;
 cin >> N;
 for(int i = 0; i < N; i++){
 cin >> a;
 ans += 1.0 / a;
 }
 ans = 1.0 / ans;
printf("%.10Lf\n", ans);
 }
