#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;
 
 
int main() {
    string s;
    cin >> s;
    vector<string> a={"Sunny","Cloudy","Rainy","Sunny"};
    rep(i,3){
        if(s==a.at(i)){
            cout << a.at(i+1) << endl;
            break;
        }
    }
}