#include<iostream>
#include<queue>
using namespace std;

int main(){
    int x,y,a,b,c;
    cin>>x>>y>>a>>b>>c;
    priority_queue<long long> rap,gap,tap;
    for(int i=0;i<a;++i){
        long long r;
        cin>>r;
        rap.push(r);
    }
    for(int i=0;i<b;++i){
        long long g;
        cin>>g;
        gap.push(g);
    }
    for(int i=0;i<c;++i){
        long long t;
        cin>>t;
        tap.push(t);
    }

    for(int i=0;i<x;++i){
        tap.push(rap.top());
        rap.pop();
    }
    for(int i=0;i<y;++i){
        tap.push(gap.top());
        gap.pop();
    }

    long long res=0;
    for(int i=0;i<x+y;++i){
        res+=tap.top();
        tap.pop();
    }

    cout<<res<<endl;
}