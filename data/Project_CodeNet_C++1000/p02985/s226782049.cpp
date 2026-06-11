#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#include<cstdio>
#include<cmath>
using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
#define ALL(x) x.begin(),x.end()
int MOD=1000000007;
struct Node{
    int no;
    int par;
    vector<Node*> child;
    void build(int i){
        no=i;
        par=i;
    }
};
struct Tree{
    int n;
    vector<Node> node;
    Tree(int k){
        n=k;
        node.resize(n+1);
        for(int i=1;i<=n;++i){
            node[i].build(i);
        }
    }
    void input(int k){
        for(int i=0;i<k;++i){
            int a,b;cin>>a>>b;
            node[a].child.push_back(&node[b]);
            node[b].child.push_back(&node[a]);
        }
    }
    void BFS(int s,int& res){
        queue<Node> que;
        int k=res;
        que.push(node[s]);
        while(!que.empty()){
            Node buf=que.front();que.pop();
            int num=buf.child.size();
            int cnt=0;
            for(int i=0;i<num;++i){
                if(buf.child[i]->no!=buf.par){
                    if(buf.par==buf.no)res*=k-1-cnt;
                    else res*=k-2-cnt;
                    res%=MOD;
                    //printf("no=%lld, res=%lld\n",buf.child[i]->no,res);
                    buf.child[i]->par=buf.no;
                    que.push(*buf.child[i]);
                    ++cnt;
                }
            }
        }
    }
    void DFS(Node& node){
        if(node.child.size()==1&&node.par!=node.no){
            return;
        }
        else{
            int num=node.child.size();
            for(int i=0;i<num;++i){
                if(node.child[i]->no!=node.par){
                    DFS(*node.child[i]);
                }
            }
        }
    }
};
signed main(){
    int n,k;cin>>n>>k;
    Tree tree(n);
    tree.input(n-1);
    int res=k;
    tree.BFS(1,res);
    cout<<res<<"\n";
    return 0;
}