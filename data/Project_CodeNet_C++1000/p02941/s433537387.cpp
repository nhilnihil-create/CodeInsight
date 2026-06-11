#include<iostream>
#include<stack>
#define DIM 200005
using namespace std;
int n, i, x, p, ok;
long long sol;
stack<int> s;
int v[DIM], w[DIM];
int main(){
    cin>> n;
    for(i = 1; i <= n; i++){
        cin>> w[i];
    }
    for(i = 1; i <= n; i++){
        cin>> v[i];
    }
    v[0] = v[n];
    v[n + 1] = v[1];
    for(i = 1; i <= n; i++){
        if(v[i] > w[i] && v[i] > v[i - 1] + v[i + 1]){
            s.push(i);
        }
    }
    while( !s.empty() ){
        i = s.top();
        s.pop();
        x = (v[i] - w[i]) / (v[i - 1] + v[i + 1]);
        sol += x;
        v[i] -= (v[i - 1] + v[i + 1]) * x;
        v[0] = v[n];
        v[n + 1] = v[1];
        p = i - 1;
        if(p == 0){
            p = n;
        }
        if(v[p] > w[p] && v[p] > v[p - 1] + v[p + 1]){
            s.push(p);
        }
        p = i + 1;
        if(p == n + 1){
            p = 1;
        }
        if(v[p] > w[p] && v[p] > v[p - 1] + v[p + 1]){
            s.push(p);
        }
    }
    ok = 1;
    for(i = 1; i <= n; i++){
        if(v[i] != w[i]){
            ok = 0;
            break;
        }
    }
    if(ok == 0){
        cout<< -1;
        return 0;
    }
    cout<< sol;
}
