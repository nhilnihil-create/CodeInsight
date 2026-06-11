#include<vector>
#include<list>
#include<iostream>
using namespace std;

int s,t,V,E;
bool flag[10100]={false};
vector<int> A[10100];
list<int> ans;

template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}

void dfs(int u){
    flag[u]=true;
    for(int i=0;i<A[u].size();++i){
        int v=A[u][i];
        if(flag[v]==false){
            dfs(v);
        }
    }
    ans.push_front(u);
}

void tp_srt(){
    for(int i=0;i<V;++i){
        if(flag[i]==false) dfs(i);
    }
}

int main(){
    cin>>V>>E;
    Fill(flag,false);
    for(int i=0;i<E;++i){
        cin>>s>>t;
        A[s].push_back(t);
    }

    tp_srt();

    for(list<int>::iterator i=ans.begin();i!=ans.end();++i){
        cout<<*i<<"\n";
    }
}
