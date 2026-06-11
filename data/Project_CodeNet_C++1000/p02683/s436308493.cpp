#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<iomanip>
#include <math.h>
using namespace std;
int main(){
    int n,m,x,f=0,ans=-1;
    cin>>n>>m>>x;
    vector<vector<int>> a(12, vector<int>(13));
    vector<int> b(13);
    vector<int> c(13);

    for(int i=0;i<n;i++){
        for(int j=0;j<m+1;j++){
            cin>>a[i][j];
        }
    }
    for(int i=0;i<pow(2,(n));i++){
        for(int j=0;j<n;j++){
            if(b[j]==1){
                for(int k=0;k<m+1;k++){
                    c[k]+=a[j][k];
                }
            }
        }
        for(int j=1;j<m+1;j++){
            if(c[j]<x){
                f=1;
            }
        }
        if(f==0&&(c[0]<ans||ans==-1)){
            ans=c[0];
        }
        f=0;
        for(int j=0;j<m+1;j++){
           c[j]=0;
        }
        b[0]++;
        for(int j=0;j<n;j++){
            if(b[j]>1){
                b[j]=0;
                b[j+1]++;
            }
        }
        

    }
    cout<<ans<<endl;


    return 0;
}
