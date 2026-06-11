#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a.at(i);
    }
    vector<int> b(n);
    for(int i=0;i<n;i++){
        cin>>b.at(i);
    }
    vector<int> c(n-1);
    for(int i=0;i<n-1;i++){
        cin>>c.at(i);
    }
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=b.at(a.at(i)-1);
        if(i!=n-1){
            if(a.at(i)+1==a.at(i+1)) sum+=c.at(a.at(i)-1);
        }
        else continue;
    }
    cout<<sum<<endl;
}