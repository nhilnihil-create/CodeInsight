#include<bits/stdc++.h>
using namespace std;
int main(){
        int x,a,n; cin>>x>>n; unordered_map<int,int>  vis; for(int i=0;i<n;i++) {cin>>a; vis[a]=1;}
        if(!vis[x]) {cout<<x<<endl; return 0;}
        int low=x-1,high=x+1;
        while(1){
                if(!vis[low]) { cout<<low<<endl; return 0;}
                if(!vis[high]) { cout<<high<<endl; return 0; }
                low--,high++;
        }
}
 