#include<bits/stdc++.h>

using namespace std;

vector<int>link;
vector<int>S;

int find(int x){
    return link[x] = ((link[x]!=x)?find(link[x]):x);
}

void unite(int a, int b){
    a = find(a);
    b = find(b);

    if(S[a]<S[b]){
        swap(a,b);
    }

    S[a] += S[b];
    link[b] = a;
}

void solve(int n, int q){
    S.assign(n,1);
    link.resize(n);

    for(int i=0;i<n;i++){
        link[i] = i;
    }

    int opt,u,v;
    while(q--){
        cin>>opt>>u>>v;

        if(opt==0){
            unite(u,v);
            continue;
        }

        if(opt==1){
            cout<<(find(u) == find(v))<<endl;
            continue;
        }
    }
}

int main(){
    int n,q;
    cin>>n>>q;
    solve(n,q);

    return 0;
}