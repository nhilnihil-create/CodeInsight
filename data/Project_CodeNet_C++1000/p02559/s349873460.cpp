#include<bits/stdc++.h>

using namespace std;
using ll = long long;

ll build(int k, vector<ll> &seg){
    if(seg[k] != -1)return seg[k];
    return seg[k] =  build(2*k,seg) + build(2*k+1, seg);
}

void update(int n, int k, vector<ll>&seg, int x){
    k += n; 
    while(k>=1){
        seg[k]+=x;
        k/=2;
    }
}

ll sum(int n, int l, int r, vector<ll>&seg){
    l+=n;
    r+=n;

    r--;
    ll s = 0;
    while(l<=r){
        if(l&1){s += seg[l];l++;}
        if((r&1)==0){s += seg[r];r--;}

        l/=2;
        r/=2;
    }

    return s;
}




void solve(int q, int n, vector<ll>a){
    vector<ll> tree(2*n,-1);
    
    int idx = n;
    for(ll ai:a){
        tree[idx] = ai;
        idx++;
    }

    build(1,tree);

    int opt, arg1, arg2;
    while(q--){
        cin>>opt>>arg1>>arg2;

        if(opt == 0){
            update(n, arg1, tree, arg2);
            continue;
        }

        if(opt == 1){
            cout<<sum(n, arg1, arg2, tree)<<endl;
            continue;
        }
    }

}

int main(){
    int n, q;
    cin>>n>>q;

    vector<ll>a(n);

    for(ll &ai:a)
        cin>>ai;

    solve(q,n,a);
    return 0;
}