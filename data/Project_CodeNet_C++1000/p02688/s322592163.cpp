#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    bool num[n];
    for(int i=0;i<n;i++){
        num[i]=true;
    }
    for(int i=0;i<k;i++){
        int d;
        cin>>d;
        for(int j=0;j<d;j++){
            int a;
            cin>>a;
            num[a-1]=false;
        }
    }
    int ans=0;
    for(int i=0;i<n;i++){
        if(num[i])
        ans++;
    }
    cout<<ans<<endl;
    return 0;

}