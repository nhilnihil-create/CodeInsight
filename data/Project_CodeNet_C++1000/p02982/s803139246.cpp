#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<iomanip>
using namespace std;

int main(){
    int n,d;
    cin>>n>>d;
    int ans=0;
    int a[n][d];
    for(int i=0;i<n;i++){
        for(int j=0;j<d;j++){
            cin>>a[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int len=0;
            for(int k=0;k<d;k++){
                len+=(a[i][k]-a[j][k])*(a[i][k]-a[j][k]);
            }
            for(int k=0;k*k<=len;k++){
                if(k*k==len)ans++;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}