#include <bits/stdc++.h>
#define f(i,j,k) for(int i=j;i<k;i++)
using namespace std;
int main(){
    long long n,k,q,a;
    cin>>n>>k>>q;
    vector<long long> ans(n,k-q);
    f(i,0,q){
        cin>>a;
        ans[a-1]++;
    }
    f(i,0,n){
        if(ans[i]>0){
            cout<<"Yes"<<endl;
        }
        else{
            cout<<"No"<<endl;
        }
    }
    return 0;
}
