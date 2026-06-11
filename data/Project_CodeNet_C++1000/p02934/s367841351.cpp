#include<bits/stdc++.h>
using namespace std;

int main(){
    float n;
    cin>>n;
    float sum = 0;
    for (int i=0;i<n;++i){
        float x;
        cin>>x;
        sum+=1/x;
    }
    float ans = 1/sum;
    cout<<ans;
}