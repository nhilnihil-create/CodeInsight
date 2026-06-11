#include <bits/stdc++.h>
using namespace std;

int main(){
    long N;cin>>N;
    vector<long> sum(N+1,0);
    vector<long> array(N+1,0);
    for(long i=0;i<N;i++){
        long a;cin>>a;
        array[i]=a;
        sum[a]++;
    }
    long res=0;
    for(long i=0;i<N+1;i++){
        res+=sum[i]*(sum[i]-1)/2;
    }
    for(long i=0;i<N;i++){
        long m=array[i];
        long ans = res-(sum[m]-1);
        cout<<ans<<endl;
    }
}