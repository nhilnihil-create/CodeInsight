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
 double ans = 0.0, a;
 cin >> N;
 for(int i = 1; i <= N; ++i){
 cin >> a;
 ans += 1.0 / a;
 }
 ans = 1.0 / ans;
printf("%.10lf\n", ans);
 }