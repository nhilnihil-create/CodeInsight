#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int main(){
    int K;
    cin>>K;
    
    queue<long long> q;
    for(int i=1;i<10;i++){
        q.push(i);
    }

    int cnt=0;
    long long node;
    while(!q.empty()){
        node=q.front();q.pop();
        cnt++;
        if(cnt==K){
            cout<<node<<endl;
            break;
        }
        int tmp=node%10;
        if(tmp!=0){
            q.push(node*10+tmp-1);
        }
        q.push(node*10+tmp);
        if(tmp!=9){
            q.push(node*10+tmp+1);
        }
    }
    

    return 0;
}