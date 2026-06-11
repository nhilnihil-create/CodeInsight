#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<iomanip>
#include <math.h>
using namespace std;
int main(){
    long long int n,d,c=0,ans=0;
    vector<vector<int>>a(1000,vector<int>(1000));
    cin>>n>>d;
    for(long long int i=0;i<n;i++){
        for(long long int j=0;j<d;j++){
            cin>>a[i][j];
        }
    }
    for(long long int i=0;i<n;i++){
        for(long long int j=i+1;j<n;j++){
            for(long long int k=0;k<d;k++){
                c+=((a[i][k]-a[j][k])*(a[i][k]-a[j][k]));
            }
            for(int k=1;k*k<=c;k++){
                if(c==k*k){
                    ans++;
                }
            }
            c=0;
        }
        
    }
    cout<<ans<<endl;
    return 0;
}
