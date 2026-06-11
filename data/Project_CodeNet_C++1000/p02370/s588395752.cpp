#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct vertex{
    vector<int> E;//cost,to
};
#define MAX_V 10000
#define MAX_E 100000

bool isVisited[MAX_V];
bool isChecked[MAX_V];
vertex V[MAX_V];
vector<int> A;

void rec(int i){
    isChecked[i]=true;
    for(auto&e:V[i].E){
        if(!isChecked[e]) rec(e);
    }
    A.push_back(i);
    return;
}

int main(){
    int nv,ne;
    cin>>nv>>ne;
    
    for(int i=0;i<ne;i++){
        int s,t;
        cin>>s>>t;
        V[s].E.emplace_back(t);
    }
    
    fill(isChecked,isChecked+MAX_V,false);
    for(int i=0;i<nv;i++){
        if(!isChecked[i]) rec(i);
    }
    for(auto ite=A.rbegin();ite!=A.rend();ite++)cout<<*ite<<endl;
    return 0;
}