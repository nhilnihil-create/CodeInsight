#include<cstdio>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
int main(){
    //priority_queue<int,greater<int> > Q;
    priority_queue<double, vector<double>, greater<double> > Q;
    int N;
    cin>>N;
    for(int i=0;i<N;i++){
        double a;
        cin>>a;
        Q.push(a);
    }
    while(2<=Q.size()){
        double a,b;
        a=Q.top();Q.pop();
        b=Q.top();Q.pop();
        Q.push((a+b)/(double)2);
    }
    cout<<Q.top()<<endl;
    return 0;
}
