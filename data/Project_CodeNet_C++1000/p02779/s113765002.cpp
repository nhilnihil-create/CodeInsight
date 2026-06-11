#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    int mario[n];
    for(int i=0;i<n;i++){
        cin>>mario[i];
    }
    int m = sizeof(mario)/sizeof(mario[0]);
    sort(mario,mario+m);
    
    for(int i=0;i<n-1;i++){
       if(mario[i]==mario[i+1]){
            cout<<"NO";
            return 0;
        }
       // cout<<mario[i];
    }
    cout<<"YES";
}
