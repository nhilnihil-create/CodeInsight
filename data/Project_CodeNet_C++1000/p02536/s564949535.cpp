#include<bits/stdc++.h>
using namespace std;
#define int long long
 
#define check(a)         cout<<#a<<" : "<<a<<endl;
#define check2(a, b)     cout<<#a<<" : "<<a<<" | "<<#b<<" : "<<b<<endl;
#define check3(a, b, c)  cout<<#a<<" : "<<a<<" | "<<#b<<" : "<<b<<" | "<<#c<<" : "<<c<<endl;


int parent[200001];
int Size[200001];

void make_set(int a){ //disjoint set union
    parent[a]=a;
    Size[a]=1;
}

int find_set(int a){
    if(parent[a]==a)return a;
    else return parent[a]=find_set(parent[a]);
}

void make_union(int a,int b){
    a=find_set(a);
    b=find_set(b);
    if(a!=b){
        if(Size[a]<Size[b])
            swap(a,b);
        parent[b]=a;
        Size[a]+=Size[b];
    }
}
void testCase(){
    int n, m; cin >> n >> m;
    for(int i = 1; i <= n; i++){
        make_set(i);
    }

    for(int i = 1; i <= m; i++){
        int a, b;
        cin >> a >> b;
        make_union(a, b);
    }

    int ans = -1;
    for(int i = 1; i <= n; i++){
        ans += (parent[i] == i);
    }

    cout << ans << '\n';

}
 
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    int t = 1;
    // int t; cin >> t;
    while(t--)
        testCase();
    
    return 0;
}