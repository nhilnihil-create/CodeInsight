#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,i;
    cin>>n;
    long long int sum=0;
    for(i=1;i<=n;i++){
        if(!(i%3==0) && !(i%5==0) /*&& !(i%15==0)*/)
        sum+=i;
    }
    cout<<sum<<endl;
}