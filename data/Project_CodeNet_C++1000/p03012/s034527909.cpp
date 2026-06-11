#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int sum=0;
    vector<int> w(n);
    for(int i=0;i<n;i++){
        cin>>w[i];
        sum+=w[i];
    }
    int mini=1e8;
    for(int i=0;i<n;i++){
        int r=0,l=sum;
        for(int j=0;j<i;j++){
            r+=w[j];
            l-=w[j];
        }
    mini=min(mini,abs(r-l));
    }
    cout<<mini<<endl;
}