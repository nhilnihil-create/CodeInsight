#include <bits/stdc++.h>
using namespace std;
int main(void){
    long long n;
    cin >>n;
    vector<bool>ans(1000000001,false);
    for(long long i=0;i<n;i++){
        long long x;
        cin >>x;
        if(ans[x]){
            cout <<"NO"<<endl;
            return 0;
        }else{
            ans[x]=true;
        }
    }
    cout <<"YES"<<endl;
}
