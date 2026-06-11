#include<bits/stdc++.h>
using namespace std;

int ans;
//recursive function
void DFS(vector<int>A,int n,int m,int q,vector<int>a,vector<int>b,vector<int>c,vector<int>d){
    // end condition
    if(A.size()==n+1){
        // calc score
        int now = 0;
        for(int i=0; i<q; i++){
            if(A[b[i]]-A[a[i]] == c[i]) now += d[i];
        }
        ans = max(ans,now);
        return;
    }

    // main procedure
    A.push_back(A.back());
    while(A.back() <= m){
        DFS(A,n,m,q,a,b,c,d);
        A.back()++;
    }
}

int main(){
    int n,m,q;
    cin >> n >> m >> q;
    vector<int> a(q);
    vector<int> b(q);
    vector<int> c(q);
    vector<int> d(q);
    for(int i=0; i<q; i++){
        cin >> a[i] >> b[i] >> c[i] >> d[i];
    }

    // full search
    DFS(vector<int>(1,1),n,m,q,a,b,c,d);
    cout << ans << endl;
    return 0;
}


