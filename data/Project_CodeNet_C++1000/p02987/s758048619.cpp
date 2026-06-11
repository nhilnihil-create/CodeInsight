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
    string s;
    cin >> s;
    char S[4];
    rep(i, 4) S[i] = s[i];
    sort(S, S + 4);
    if(S[0] == S[1] && S[2] == S[3] && S[1] != S[2]) cout << "Yes" << endl;
    else cout << "No" << endl;
}