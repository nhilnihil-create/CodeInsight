#include<bits/stdc++.h>
using namespace std;
int work(int i,int j){
    i--,j--;
    int xxx=i^j,ans=0;
    while(xxx){
        ans++,xxx>>=1;
    }
    return ans;
}
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            cout<<work(i,j)<<" ";
        }
        cout<< endl;
    }
    return 0;
}