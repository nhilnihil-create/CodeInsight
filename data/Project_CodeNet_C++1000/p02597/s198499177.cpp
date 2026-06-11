#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    string c;
    cin>>n>>c;
    int w=0,r=0;
    for(int i=0;i<n;i++){
        if(c[i]=='R') r++;
    }
    int ans=1e9;
    for(int i=0;i<=n;i++){
        if(i-1>=0&&c[i-1]=='W') w++;
        else if(i-1>=0&&c[i-1]=='R') r--;
        ans=min(ans,max(w,r));
    }
    cout<<ans<<endl;
}