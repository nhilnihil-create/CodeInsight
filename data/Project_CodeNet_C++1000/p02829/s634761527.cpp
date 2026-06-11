#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using ll=long long;
using namespace std;

int main(){
    int a,b;
    cin>>a>>b;
    vector<int> num(4,0);
    
    num[a]++;
    num[b]++;
    
    for(int i=1;i<=3;i++){
        if(num[i]==0)
            cout<<i<<endl;
    }
    
    return 0;
}