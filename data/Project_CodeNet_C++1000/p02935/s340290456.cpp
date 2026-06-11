#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    priority_queue<double,vector<double>,greater<double> >que;
    for(int i=0;i<n;i++){
        double v;
        cin >> v;
        que.push(v);
    }
    while(que.size()>1){
        double a = que.top();
        que.pop();
        double b = que.top();
        que.pop();
        que.push((a+b)/2);
    }
    cout<<que.top()<<endl;
}