#include<bits/stdc++.h>
using namespace std;
vector<int> vis((int)1e6+5,0);
int main(){
        int n; cin>>n;
        int a[n]; for(int i=0;i<n;i++) cin>>a[i];
        for(int i=0;i<n;i++) vis[a[i]]++; int cnt=0;
        for(int i=0;i<n;i++) {
                if(vis[a[i]]>1) continue;
                if(a[i]==1){ cnt++; continue;}
                int flag=0;
                for(int j=1;j*j<=a[i];j++){
                	if(j==1) { if(vis[j]){flag=1; break;}  }
                    else if(!(a[i]%j)&&(vis[j]||vis[a[i]/j])) {flag=1; break;}
                }
                if(!flag)cnt++;
        }
        cout<<cnt<<endl;
}