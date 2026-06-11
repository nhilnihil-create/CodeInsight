#include <bits/stdc++.h>
#define f(i,j,k) for(int i=j;i<k;i++)
using namespace std;
int main(){
    long long n;
    cin>>n;
    vector<long long> a;
    for(long long i=1;i*i<=n;i++){
        if(n%i==0){
            a.push_back(i+n/i-2);
        }
    }
    sort(a.begin(),a.end());
    cout<<a[0]<<endl;
    return 0;
}
