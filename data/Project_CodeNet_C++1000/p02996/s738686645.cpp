#include "bits/stdc++.h"
using namespace std;
int main(){
    int N,time=0;
    bool f=true;
    cin >>N;
    vector<pair<int,int>> task;
    for(int i=0;i<N;i++){
        int a,b;
        cin>>a>>b;
        task.emplace_back(b,a);
    }
    sort(task.begin(),task.end());
    for(int i=0;i<N;i++){
      	time+=task[i].second;
        if(time>task[i].first){
            f=false;
            break;
        }
    }
    if(f) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}
