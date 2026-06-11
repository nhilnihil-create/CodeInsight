#include <bits/stdc++.h>
using namespace std;
int main() { 
    int n,a,b,val=0;
    std::vector<int> v;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        if(a==b) val+=1;
        else{
            v.push_back(val);
            val=0;
        }
    }
    v.push_back(val);
    sort(v.begin(),v.end());
    int x=v[v.size()-1];
    if(x>=3)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}
