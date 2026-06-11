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
    string s;
    cin >> n >> s;
    if(n % 2 == 1){
        cout << "No" << endl;
        return 0;
    }

    int hn = n / 2;
    rep(i, n / 2){
        if(s[i] != s[i+hn]){
            cout << "No" << endl;
            return 0; 
        }
    }
    cout << "Yes" << endl;
}