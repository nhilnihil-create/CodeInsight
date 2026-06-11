#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    vector<int>p(n);
    for(int i=0;i<n;i++) cin>>p.at(i);
    
    sort(p.begin(),p.end());
    if(n%2==0){
        cout<<p.at(n/2)-p.at(n/2-1);
    }
    else{
        cout<<"1"<<endl;
    }

    
}
