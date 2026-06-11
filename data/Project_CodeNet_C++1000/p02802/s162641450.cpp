#include <bits/stdc++.h>
#define f(i,j,k) for(int i=j;i<k;i++)
using namespace std;
int main(){
    long long n,m,ac=0,wa=0;
    cin>>n>>m;
    long long p;
    vector<long long> a(n+1,0),w(n+1,0);
    string s;
    f(i,0,m){
        cin>>p>>s;
        if(s=="AC"&&a[p]==0){
            a[p]++;
        }
        else if(s=="WA"&&a[p]==0){
            w[p]++;
        }
    }
    f(i,1,n+1){
        ac+=a[i];
        if(a[i]!=0){
            wa+=w[i];
        }
    }
    cout<<ac<<" "<<wa<<endl;
    return 0;
}
