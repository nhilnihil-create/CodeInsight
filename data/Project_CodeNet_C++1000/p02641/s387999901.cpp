#include<bits/stdc++.h>
using namespace std;
int main(){
    int x,n;
    cin>>x>>n;
    vector<int> p(n,0);
    for(int i=0;i<n;i++){
        cin>>p[i];
    }
    int min=51;
    int ans=0;
    for(int i=0;i<=101;i++){
        if(min>abs(x-i)){
            bool flag=true;
            for(int j=0;j<n;j++){
                if(p[j]==i)flag=false;
            }
            if(flag){
                min=abs(x-i);
                ans=i;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
