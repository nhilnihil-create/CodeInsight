#include <bits/stdc++.h>
#define ll long long
#define ar array
#define AC ios_base::sync_with_stdio(0); cin.tie(NULL);
using namespace std;
const int M = 1e9+7;
const int N = 1e5;
int n, m ,q;
vector<int> arr;
struct query{
    int a, b, c, d;
} q_arr[55];
int ans = 0;

void dfs(int num, int pos){
    if(pos>=n){
        int tmp = 0;
        for(int i=0; i<q; i++){
            int a = q_arr[i].a, b=q_arr[i].b;
            if(arr[b]-arr[a]==q_arr[i].c){
                tmp+=q_arr[i].d;
            }
        } 
        ans = max(ans, tmp);
        return;
    }
    for(int i = num; i<=m; i++){
        arr.push_back(i);
        dfs(i, pos+1);
        arr.pop_back();
    }
}

int main(){
    AC
    cin>>n>>m>>q;
    for(int i=0; i<q; i++){
        cin>>q_arr[i].a>>q_arr[i].b>>q_arr[i].c>>q_arr[i].d;
        q_arr[i].a--;
        q_arr[i].b--;
    }
    dfs(1, 0);
    cout<<ans<<endl;
}