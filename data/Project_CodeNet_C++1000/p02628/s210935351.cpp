#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n,k;
    cin>>n>>k;
    int mario[n];
    for(int i=0;i<n;i++){
        cin>>mario[i];
    }
    sort(mario,mario+n);
    int res=0;
    for(int j=0;j<k;j++){
        res+=mario[j];
    }
    cout<<res;

}
