#include<iostream>
#include<vector>
#include<map>
using namespace std;
using ll = long long;

int main(){
    int n;
    cin>>n;
    map<int,int> m;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
        m[a[i]]++;
    }
    int k=m.size();
    bool ans=false;
    if(m[0]==n){
        ans=true;
    }else if(n%3==0&&m[0]==n/3&&k==2){
        ans=true;
    }else if(n%3==0&&k==3){
        ll s=0;
        bool flag=true;
        for(auto p : m){
            if(p.second&&p.second!=n/3) flag=false;
            s^=p.first;
        }
        if(flag&&s==0) ans=true;
    }
    if(ans) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}