#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<math.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define mod 1000000007
using namespace std;
int main(){
    int n;  cin>>n;
    vector<int> R(n);
    rep(i,n) cin>>R[i];
    
    int maxV=-2000000000;
    int minV=R[0];
    for(int i=1;i<n;++i){
        maxV=max(maxV,R[i]-minV);
        minV=min(minV,R[i]);
    }
    cout<<maxV<<endl;
}
