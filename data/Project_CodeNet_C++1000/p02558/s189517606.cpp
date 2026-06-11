#include <iostream>
using namespace std;

const int N= 200001;
int parent[N];

void make_set(int r){
    parent[r]=r;
}

int find_set(int r){
    if(parent[r]==r){
        return r;
    }else{
        return parent[r]=find_set(parent[r]);
    }
}

void union_set(int a, int b){
    a= find_set(a);
    b=find_set(b);
    if(a!=b){
        parent[b]=a;
    }
}

int main(){
    int n,q;
    cin>>n>>q;
    for(int i=0;i<n;++i){
        make_set(i);
    }
    for(int i=0; i<q; ++i){
        int t,u,v;
        cin>>t>>u>>v;
        if(t==0){
            union_set(u,v);
        }else{
            cout<<((find_set(u)==find_set(v))? 1:0)<<endl;
        }
    }
    return 0;
}