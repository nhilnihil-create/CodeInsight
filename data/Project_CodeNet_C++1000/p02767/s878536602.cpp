#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,sum,med;
    cin>>n;
    int t[n];
    sum = 0;
    for(int i = 0;i<n;++i){
        cin>>t[i];
        sum += t[i];
    }
    med = round((double)sum/n);
    sum = 0;
    for(int i = 0;i<n;++i){
        sum += (t[i]-med)*(t[i]-med);
    }
    cout<<sum;
    return 0;
}