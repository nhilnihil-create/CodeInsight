#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int main(){
    int N,X,Y;
    cin>>N>>X>>Y;
    vector<int> ans(N-1,0);

    for(int i=1;i<=N;i++){
        queue<int> q;
        vector<int> d(N+1,-1);
        q.push(i);
        d[i]=0;
        while(!q.empty()){
            int n=q.front();q.pop();
            //cout<<n<<endl;
            if(n<N && d[n+1]==-1){
                q.push(n+1);
                d[n+1]=d[n]+1;
            }
            if(n>1){
                if(d[n-1]==-1){
                    q.push(n-1);
                    d[n-1]=d[n]+1;
                }
            }
            if(n==X && d[Y]==-1){
                q.push(Y);
                d[Y]=d[X]+1;
            }
        }
        for(int j=i+1;j<=N;j++){
            //cout<<d[j]<<" ";
            ans[d[j]-1]++;
        }
        //cout<<endl;
    }

    for(auto p:ans){
        cout<<p<<endl;
    }
    
    return 0;
}