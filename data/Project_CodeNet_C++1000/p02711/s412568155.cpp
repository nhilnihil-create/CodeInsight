#include <bits/stdc++.h>
#include <math.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using ll = long long;
using vec = vector<char>;
using vec2 = vector<vector<ll>>;
ll inf = pow(2,62);

int main(){
    string n;
    cin >> n;
    if(n.at(0) == '7' || n.at(1) == '7' || n.at(2) == '7'){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}