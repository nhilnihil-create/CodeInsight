#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int n,m,q;
int a[50],b[50],c[50],d[50];
int ans = 0;

void dfs(vector<int> A){
    if(A.size()==n){
        int tmp = 0;
        for(int i=0;i<q;i++){
            if(A[b[i]]-A[a[i]]==c[i])  tmp += d[i]; 
        }
        ans = max(ans,tmp);

    }else{
        int back = 1;
        if(A.size()>0) back = A.back(); 
        for(int i=back;i<=m;i++){
            A.push_back(i);
            dfs(A);
            A.pop_back();
        }
    }
}

int main(void){
    cin >> n >> m >> q;

    for(int i=0;i<q;i++) cin >> a[i] >> b[i] >> c[i] >> d[i];
    for(int i=0;i<q;i++){a[i]--; b[i]--;}
    dfs({});
    cout << ans << endl;
    return 0;
}