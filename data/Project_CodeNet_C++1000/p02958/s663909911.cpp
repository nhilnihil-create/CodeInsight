#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;cin>>n;
    vector<int> p(n);
    for(int i=0;i<n;i++)cin>>p[i];
    bool res=false;
    bool check0=1;
    for(int i=0;i<n-1;i++){
        if(p[i]>p[i+1])check0=0;
        if(i==n-2&&check0)res=true;
    }
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            vector<int> q=p;
            int c=q[j];
            q[j]=q[i];
            q[i]=c;
            bool check=1;
            for(int k=0;k<n-1;k++){
                if(q[k]>q[k+1])check=0;
                if(k==n-2&&check){
                  res=true;
                }
                }
        }
    }
    if(res)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}