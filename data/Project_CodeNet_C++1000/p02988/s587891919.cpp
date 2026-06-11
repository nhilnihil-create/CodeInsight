#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;
 
 
int main() {
    int n;
    cin >> n;
    vector<int> p(n);
    rep(i,n) cin >> p.at(i);
    int count=0;
    rep(i,n-2){
        if((p.at(i)-p.at(i+1))*(p.at(i+2)-p.at(i+1))<0)count++;
    }
    cout << count << endl;
}