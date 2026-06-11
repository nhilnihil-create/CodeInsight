#include<bits/stdc++.h>
using namespace std;
#define N 1000100
#define ll long long
int f[N];
int find(int x){
    if(f[x] != x) f[x] = find(f[x]);
    return f[x];
}
int merge(int a,int b){
    int t1 = find(a);
    int t2 = find(b);
    if(t1 != t2){
        f[t2] = t1;
        return 1;
    }
    return 0;
}
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i = 0; i <= n; i++){
        f[i] = i;
    }
    int sum = 0;
    while(m--){
        int x,y;
        cin>>x>>y;
        if(merge(x,y)){
            sum++;
        }
    }
    cout<<n-1-sum;
    return 0;
}
