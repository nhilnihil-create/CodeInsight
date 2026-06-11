#include<bits/stdc++.h>
using namespace std;

int main(){
    double N, buf;
    cin >> N;
    priority_queue<double, vector<double>, greater<double>> v;
    for(int i = 1; i <= N; ++i){
        cin >> buf;
        v.push(buf);
    }
    while(v.size() > 1){
        double x = v.top(); v.pop();
        double y = v.top(); v.pop();
        v.push((x+y)/2);
    }
    cout << v.top() << endl;
    return 0;
}