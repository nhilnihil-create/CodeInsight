#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; cin>>n;
    vector<int> s(n);
    vector<int> t(n);
    for(int i=0;i<n;i++){
    cin>>s.at(i);
    t.at(i)=s.at(i);
    }
    sort(t.begin(),t.end());
    int count=0;
    for(int i=0;i<n;i++){
        if(s.at(i)!=t.at(i)) count++;
    }
    if(count==0||count==2) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}
