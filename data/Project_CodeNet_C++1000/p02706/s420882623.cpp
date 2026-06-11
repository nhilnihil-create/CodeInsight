#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int k,n;
    cin>>k>>n;
    int mario[n];
    long sum=0;
    for(int i=0;i<n;i++){
        cin>>mario[i];
        sum+=mario[i];
    }
    if(k-sum<0)
        puts("-1");
    else
        cout<<k-sum;
}
