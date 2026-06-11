#include<bits/stdc++.h>
using namespace std;
#define rep(n,k) for(int i = (int)n;i<k;i++)
using Int =long long int;
using Graph =vector<vector<int>>;
int main(){
    int N;cin>>N;
    priority_queue<int>que;
    rep(0,N){
        int a;cin>>a;
        que.push(a);
    } 
    Int sum = que.top();
    que.pop();
    bool parity = (que.size()-1)%2 != 0;//き数か？
    int loop = (que.size()-1)/2;
   
    rep(0,loop){
        sum+= 2*que.top();
        que.pop();
    }
    if(parity)sum+=que.top();
    cout<<sum<<endl;

    
}