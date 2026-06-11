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
    string a[] = {"SUN","MON","TUE","WED","THU","FRI","SAT"};
    rep(i, 7){
        if(a[i] == s){
            cout << 7 - i << endl;
        }
    }
}