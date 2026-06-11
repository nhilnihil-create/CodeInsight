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
    for (int i = 1; i <= s.size(); i++){
        if(i % 2 == 1 && s[i-1] == 'L'){
            cout << "No" << endl;
            return 0;
        }
        if(i % 2 == 0 && s[i-1] == 'R'){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;

}