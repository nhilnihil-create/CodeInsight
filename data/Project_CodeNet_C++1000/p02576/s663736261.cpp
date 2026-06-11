#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cstdlib>
#include<queue>
#include<set>
#include<cstdio>

using namespace std;

#define ll long long
#define rep(i, n) for(int i = 0; i < n; i++)
#define P pair<int, int>

typedef vector<int> vec;
typedef vector<vec> mat;

int main(){
    int n, x, t;
    cin >> n >> x >> t;
    if(n % x == 0) cout << n / x * t << endl;
    else  cout << (n / x + 1) * t << endl;
}