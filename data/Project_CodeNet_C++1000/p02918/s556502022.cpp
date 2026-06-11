#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main(){
    int n,k;cin>>n>>k;
    string s;cin>>s;
    vector<int> v;
    for(int i=0;i<n;){
        int cnt=0;
        char c=s[i];
        while(c==s[i]){
            cnt++;
            i++;
        }
        v.push_back(cnt);
    }
    if((int)v.size()<=2*k+1){
        cout<<n-1<<endl;
        return 0;
    }
    int sum=0;
    for(int i=0;i<=2*k;i++){
        sum+=v[i];
    }
    int ans=sum-1;
    for(int i=2*k+1;i<(int)v.size();i++){
        ans+=v[i]-1;
    }
    cout<<ans<<endl;
    return 0;
}