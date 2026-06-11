#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
    int n;
    cin >> n;
    vector<pair<int,int>> p;
    rep(i,n){
        int a,b;
        cin >> a >> b;
        p.emplace_back(b,a);
    }
    string c = "Yes";
    sort(p.begin(),p.end());
    long sum = 0;
    for(auto i:p){
        long x = i.first,y=i.second;
        sum += y;
        if(x<sum) c = "No";
    }
    cout << c << endl;
}