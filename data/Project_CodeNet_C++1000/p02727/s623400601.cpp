#include<bits/stdc++.h>

using namespace std;

pair<int,int> a[300005];

int X, Y, A, B, C;

priority_queue<int>q1,q2,q3,q4;

int main(){
    scanf("%d%d%d%d%d", &X, &Y, &A, &B, &C);

    for(int i=1;i<=A+B+C;++i){
        int x;scanf("%d",&x);
        if(i<=A){
            q1.push(x);
        }else if(i<=A+B){
            q2.push(x);
        }else{
            q3.push(x);
        }
    }

    long long res=0;
    for(int i=1;i<=X;++i){
        res+=q1.top();
        q4.push(-q1.top());
        q1.pop();
    }

    for(int i=1;i<=Y;++i){
        res+=q2.top();
        q4.push(-q2.top());
        q2.pop();
    }

    while(!q3.empty()&&q3.top()>-q4.top()){
        res+=q4.top();
        q4.pop();
        res+=q3.top();
        q3.pop();
    }

    printf("%lld",res);

    return 0;
}
