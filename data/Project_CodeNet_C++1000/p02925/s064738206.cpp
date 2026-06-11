#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> vec;
vector<vector<int>> now;
bool dfs(int i){
    int ii=now.at(i).at(0);
    if(ii==-1){return false;}
    if(now.at(ii).at(0)==i){return true;}
    else{return false;}
}
int main(){
    int N;
    cin>>N;
    vec.resize(N,vector<int>(N-1));
    now.resize(N,vector<int>(0));
    vector<int> enemy(N);
    for(int i=0;i<N;i++){//O(N^2)
        for(int j=0;j<N-1;j++){
            int a;
            cin>>a;
            vec.at(i).at(j)=a-1;
            if(j==0){
                now.at(i).push_back(a-1);
            }
        }
        enemy.at(i)=0;
    }
    long long count=0;
    long long day=1;
    unordered_map<int,int> mp;
    unordered_map<int,int> mp2;
    queue<int> que;
    for(int i=0;i<N;i++){
        //cout<<i<<" "<<now.at(i).at(0)<<endl;
        if(dfs(i) && mp[i]==0 && mp[now.at(i).at(0)]==0){
            //cout<<i<<" "<<now.at(i).at(0)<<endl;
            count++;
            int a=i;
            int b=now.at(i).at(0);
            enemy.at(a)++;
            enemy.at(b)++;
            mp[a]=1;
            mp[b]=1;
                //cout<<a<<" "<<b<<"   "<<enemy.at(a)<<" "<<enemy.at(b)<<endl;
                if(enemy.at(a)<N-1){
                    //cout<<a<<" "<<b<<" "<<enemy.at(a)<<endl;
                    now.at(a).at(0)=vec.at(a).at(enemy.at(a));
                }
                else{
                    now.at(a).at(0)=-1;
                }
                if(enemy.at(b)!=N-1){
                    //cout<<" "<<a<<" "<<b<<" "<<enemy.at(b)<<endl;
                    now.at(b).at(0)=vec.at(b).at(enemy.at(b));
                }
                else{
                    now.at(b).at(0)=-1;
                }
            }
            if(dfs(i) && mp2[i]==0 && mp2[now.at(i).at(0)]==0){
                //cout<<i<<" "<<now.at(i).at(0)<<endl;
                que.push(i);
                mp2[i]++;
                mp2[now.at(i).at(0)]++;
            }
        }
    //countはN(N-1)/2まで
    while(count<N*(N-1)/2){//O(N^2)
        day++;
        int memo=count;
        queue<int> q;
        //cout<<" "<<que.size()<<endl;
        for(int i=0;i<(int)q.size();i++){
            //cout<<que.front()<<endl;
        }
        while(!que.empty()){
            count++;
            int a=que.front();
            int b=now.at(a).at(0);
            //cout<<a<<" "<<b<<endl;
            que.pop();
            enemy.at(a)++;
            enemy.at(b)++;
            mp[a]=1;
            mp[b]=1;
            //cout<<a<<" "<<b<<"   "<<enemy.at(a)<<" "<<enemy.at(b)<<endl;
            if(enemy.at(a)<N-1){
                //cout<<a<<" "<<b<<" "<<enemy.at(a)<<endl;
                now.at(a).at(0)=vec.at(a).at(enemy.at(a));
            }
            else{
                now.at(a).at(0)=-1;
            }
            if(enemy.at(b)!=N-1){
                //cout<<" "<<a<<" "<<b<<" "<<enemy.at(b)<<endl;
                now.at(b).at(0)=vec.at(b).at(enemy.at(b));
            }
            else{
                now.at(b).at(0)=-1;
            }
            //cout<<a<<" "<<b<<"   "<<now.at(a).at(0)<<" "<<now.at(b).at(0)<<endl;
            if(dfs(a)){
                //cout<<a<<endl;
                q.push(a);
            }
            if(dfs(b)){
                //cout<<b<<endl;
                q.push(b);
            }
        }
        que=q;
        if(memo==count){
            cout<<-1<<endl;
            return 0;
        }
    }
    cout<<day<<endl;
}