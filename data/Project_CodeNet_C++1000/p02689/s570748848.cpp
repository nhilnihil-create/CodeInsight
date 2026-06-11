#include<bits/stdc++.h> 
using namespace std;
using ll = long long;

#define fast_io ios_base::sync_with_stdio(false) ; cin.tie(0); cout.tie(0);

int main() {
    fast_io;
    int n,m;
    cin>>n>>m;

    vector<int> height(n);
    vector<bool> accept(n);
    accept.assign(n,true);
    for(int i=0;i<n;i++) {
        int h;
        cin>>h;
        height[i]=h;
    }

    for(int i=0;i<m;i++) {
        int a,b;
        cin>>a>>b;

        if(height[a-1]<height[b-1]) {
            accept[a-1]=false;
        }
        else if (height[a-1]>height[b-1]) {
            accept[b-1]=false;
        }
        else {
            accept[b-1]=false;
            accept[a-1]=false;
        }
    }

    int ans=0;
    for(int i=0;i<n;i++) {
        if(accept[i]) {
            ans++;
        }
    }

    cout<<ans<<endl;


}


