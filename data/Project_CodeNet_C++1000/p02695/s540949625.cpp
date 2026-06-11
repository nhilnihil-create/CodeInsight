#include <bits/stdc++.h>
using namespace std;

int N, M, Q;
vector<long long> a,b,c,d;

long long score(vector<int> A){
    long long score=0;
    for(int i=0;i<Q;i++){
        if(A[b[i]]-A[a[i]]==c[i])score+=d[i];
    }
    return score;
}


long long depthFirstSearch(vector<int>& A){
    long long res=0;
    if(A.size()==N){
        return score(A);  
    }    
    int prev_last=(A.empty()?0:A.back());
    for(int i=prev_last;i<M;i++){
        A.emplace_back(i);
        res=max(depthFirstSearch(A),res);
        A.pop_back();
    }
    return res;
}

int main(){
    cin>>N>>M>>Q;
    a.resize(Q);
    b.resize(Q);
    c.resize(Q);
    d.resize(Q);
    for(int i=0;i<Q;i++){
        cin>>a[i]>>b[i]>>c[i]>>d[i];
        --a[i];
        --b[i];
    }
    vector<int> A;
    cout<<depthFirstSearch(A);
    return 0;
}