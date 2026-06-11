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

vector<string> res;
int N;
void solve(int n, string s, char lim){
    if(n == 0)return;
    if(s.size() == N)res.push_back(s);
    for(char c = 'a'; c <= lim + 1; c++){

        if(c != lim + 1)solve(n - 1, s + c, lim);
        else solve(n - 1, s + c, (char)(lim + 1));
    }
}

int main(){
    cin >> N;
    solve(N, "a", 'a');
    sort(ALL(res));
    for(string s : res)cout << s << endl;
}

