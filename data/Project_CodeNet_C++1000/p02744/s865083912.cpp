#include<iostream>
#include<stdio.h>
//#include <bits/stdc++.h>
#include<vector>
#include<float.h>
#include<iomanip>
#include<algorithm>
#include<string>
#include<cstring>
#include<math.h>
#include<cmath>
#include<sstream>
#include<set>
#include<map>
#include<queue>
#include <cassert>
#include <cmath>
#include<cstdint>

#define INF 1e9
#define rep(i,n)for(int i=0;(i)<(int)(n);i++)
#define REP(i,a,b)for(int i=(int)(a);(i)<=(int)(b);i++)
#define VEC(type, c, n) std::vector<type> c(n);for(auto& i:c)std::cin>>i;
#define vec(type,n) vector<type>(n)
#define vvec(m,n) vector<vector<int>> (int(m),vector<int>(n))
#define ALL(a)  (a).begin(),(a).end()


using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using P = pair<ll, ll>;

vector<string> list;

void solve(int n, string s, int lim){
    if(n == 1){
        list.push_back(s);
        return;
    }
    for(int i = 0; i <= lim + 1; i++){
        char c = ('a' + i);
        string t = s;
        t.push_back(c);
        if(i != lim + 1)solve(n - 1, t, lim);
        else solve(n - 1, t, lim + 1);
    }
}

int main(){
    int n;
    cin >> n;
    string s = "a";
    solve(n, s, 0);
    sort(ALL(list));
    for(auto l : list)cout << l << endl;
}
