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
    string n;
    cin >> n;
    int mod = 0;
    rep(i, n.size()){
        int num = n[i] - '0';
        mod += num;
        mod %= 9;
    }
    if(mod == 0) cout << "Yes" << endl;
    else cout << "No" << endl;
}