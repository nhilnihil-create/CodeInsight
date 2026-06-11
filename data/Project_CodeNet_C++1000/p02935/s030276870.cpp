#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
    int n;
    cin >> n;
    priority_queue<double, vector<double>, greater<double>> q;
    rep(i,n){
        double v;
        cin >> v;
        q.push(v);
    }
    rep(i,n-1){
        double x = q.top();
        q.pop();
        double y = q.top();
        q.pop();
        q.push((x+y)/2.0);
    }
    cout << q.top() << endl;
}