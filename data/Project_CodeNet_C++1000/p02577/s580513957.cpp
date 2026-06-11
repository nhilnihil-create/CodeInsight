#include <bits/stdc++.h>
using namespace std;

int main(){
    string n;
    cin>>n;
    int mod=0;
    for(int i=0;i<n.size();i++){
        int tmp = n[i]-'0';
        mod = (mod+tmp)%9;
    }
    if(mod==0) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}