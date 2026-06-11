#include<bits/stdc++.h>
using namespace std;
#define int long long

const int mxN=1e5+1;
vector<string>op(mxN);
vector<int>a(51),b(51),c(51),d(51);
int n,m,q;
int ans;

void get(vector<int>v){
    if(v.size()==n)
    {
//        for(int i=0;i<v.size();i++)
//            cout<<v[i]<<" ";
//        cout<<endl;
//        cout<<n<<endl;
        int res=0;
        for(int i=0;i<q;i++)
        {
            if((v[b[i]]-v[a[i]])==c[i])
                res+=d[i];
        }
        ans=max(ans,res);
        return;
    }
    int start=1;
    if(v.size()>0)
        start=v.back();
    for(int i=start;i<=m;i++){
        v.push_back(i);
        get(v);
        v.pop_back();
    }
}

signed main(){
    cin>>n>>m>>q;
    for(int i=0;i<q;i++)
    {
        cin>>a[i]>>b[i]>>c[i]>>d[i];
        a[i]-=1,b[i]-=1;
    }
    vector<int>v;
    get(v);
    cout<<ans<<endl;
}