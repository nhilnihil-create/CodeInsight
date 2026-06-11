#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<vector<int>> c(10,vector<int>(10));
    for(int i=1;i<=n;++i){
        int temp=i;
        while(temp/10) temp/=10;
        ++c[temp][i%10];        
    }
    long long ans=0;
    for(int i=0;i<10;++i){
        for(int j=0;j<10;++j){
            ans+=c[i][j]*c[j][i];
        }
    }
    cout<<ans<<endl;
}