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

const ll mod = 1000000007;

int main(){
    int n;
    cin >> n;
    P a[n];
    rep(i, n){
        int s;
        cin >> s;
        a[i] = P(s, i);
    }
    sort(a, a + n);
    rep(i, n){
        cout << a[i].second + 1 << " ";
    }cout << endl;
}