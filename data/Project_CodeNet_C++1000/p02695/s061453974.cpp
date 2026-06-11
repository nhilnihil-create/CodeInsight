#include<bits/stdc++.h> 
using namespace std;
using ll = long long;

#define fast_io ios_base::sync_with_stdio(false) ; cin.tie(0); cout.tie(0);
int ans;
int n,m,q;
vector<int> a,b,c,d;

void dfs(vector<int> arr, int pos) {
    if(arr.size()==n) {
        int total_cost=0;
        for(int i=0;i<q;i++) {
            if(arr[b[i]]-arr[a[i]]==c[i]) {
                //cout<<"this is necessary info: "<<endl;
                //cout<<arr[b[i]]<<' '<<arr[a[i]]<<' '<<c[i]<<endl;
                //cout<<'[';
                //for(int z=0;z<arr.size();z++) {
                //    cout<<arr[z]<<',';
                //}
                //cout<<']'<<endl;
                total_cost+=d[i];
            }
        }
        ans=max(ans,total_cost);

        return;
    }

    for(int i=pos;i<=m;i++) {
        arr.push_back(i);



        dfs(arr,i);
        arr.pop_back();
    }

    return;
}

int main() {
    fast_io;
    cin>>n>>m>>q;

    a=b=c=d=vector<int>(q);

    for(int i=0;i<q;i++) {
        cin>>a[i]>>b[i]>>c[i]>>d[i];
        a[i]--;
        b[i]--;
    }

    ans=0;

    vector<int> arr(0);

    dfs(arr,1);
    cout<<ans<<endl;
}


