#include <bits/stdc++.h>
using namespace std;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout<<fixed<<setprecision(15);

    long long n;
    cin>>n;
    long long a[n],cntr=0;
    for(int i=0; i<n; i++){
        cin>>a[i];
        if(a[i]==cntr+1){
            cntr++;
        }
    }
    
    if(cntr==0){
        cout<<-1<<endl;
    }else{
        cout<<n-cntr<<endl;
    }
    return 0;
}