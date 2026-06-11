#include "bits/stdc++.h"

using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

    vector<int> pnums(300000,0);
    for(int i=2;i<300000;i++) pnums[i]=1;
    for(int i=2;i*i<300000;i++){
        if(pnums[i]){
            for(int j=i*i;j<300000;j+=i){
                pnums[j]=0;
            }
        }
    }
    vector<int> res(300000,0);
    for(int i=1;i<300000;i++) res[i]=res[i-1]+pnums[i];
    int n;
    while(cin>>n,n){
        cout<<res[2*n]-res[n]<<endl;
    }
}