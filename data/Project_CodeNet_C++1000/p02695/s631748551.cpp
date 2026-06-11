#include <bits/stdc++.h>
using namespace std;

int N,M,Q;
vector<int>a;
vector<int>b;
vector<int>c;
vector<int>d;

int score(vector<int> A){
    int cnt=0;
    for(int i=0;i<Q;i++){if(A[b[i]]-A[a[i]]==c[i]){cnt+=d[i];}}
    return cnt;
}

int ans=0;
int dfs(vector<int> A) {
    if (A.size() == N) {
        return score(A);
    }
    
    int l;
    if(A.empty()==0){l=A.back();}
    else{l=0;}
    for (int i = l; i< M;i++) {
        A.push_back(i);
        ans=max(ans,dfs(A));
        A.pop_back(); 
    }
    return ans;
}

int main() {
    cin>>N>>M>>Q;
    a.resize(Q);b.resize(Q);c.resize(Q);d.resize(Q);
    for(int i=0;i<Q;i++){
        cin>>a[i]>>b[i]>>c[i]>>d[i];
        a[i]--;b[i]--;
    }
    vector<int>A;
    cout<<dfs(A)<<endl;;
}
