#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<iomanip>
#include <math.h>
using namespace std;
int main(){
    int n,m,f=0,sum=0;
    cin>>n>>m;
    vector<int>a(1000000);
    for(int i=0;i<n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    sort(a.begin(),a.end(),greater<>());
    for(int i=0;i<m;i++){
        if(4*a[i]*m<sum){
            f=1;
            break;
        }
    }
    if(f==1){
        cout<<"No"<<endl;
    }
    else{
        cout<<"Yes"<<endl;
    }
    return 0;
}
