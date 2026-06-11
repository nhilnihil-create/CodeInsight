#include <cstdio>
#include<iostream>
#include<map>
#include<algorithm>
#include<vector>
#include <cmath>
#include <iomanip>
#include <regex>
#include <queue>
#include <set>
using namespace std;
using ll = long long;
using Lf = long double;
using plong = pair<ll,ll>;
const int mod = 1000000007;
int main(){
    ll H,W,N;
    cin>>H>>W>>N;
    ll a = max(H,W);
    cout<<ceil((double)N/a)<<endl;
    

}