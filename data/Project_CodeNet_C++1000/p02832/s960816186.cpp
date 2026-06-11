#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<long long> a(n);
    for(int i=0;i<n;++i) cin>>a[i];

    long long cur=1;
    long long ans=0;
    for(int i=0;i<n;++i){
        if(a[i]!=cur){
            ++ans;
            continue;
        }
        ++cur;
    }

    bool flag=false;
    for(int i=0;i<n;++i){
        if(a[i]==1){
            flag=true;
            break;
        }
    }

    if(!flag) cout<<-1<<endl;
    else cout<<ans<<endl;
}