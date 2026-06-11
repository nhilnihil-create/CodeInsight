#include<iostream>
#include<queue>
using namespace std;

int main(){
    int k;
    cin>>k;
    queue<unsigned long long> que;
    for(long long i=1;i<10;++i) que.push(i);
    for(long long i=0;i<k-1;++i){
        long long x=que.front();
        que.pop();
        if(x%10!=0) que.push(10*x+x%10-1);
        que.push(10*x+x%10);
        if(x%10!=9) que.push(10*x+x%10+1);
    }

    cout<<que.front()<<endl;
}