#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,saidai=0;
    cin >> n;
    vector<int> a(n),b;
    for (int i=0;i<n;i++){
        cin>>a.at(i);
    }
    b=a;
    sort(b.begin(),b.end());
    reverse(b.begin(),b.end());
    saidai=b.at(0);
    for(int i=0;i<n;i++){
        if(saidai==a.at(i)){
            cout<<b.at(1)<<endl;
        }else{
            cout<<b.at(0)<<endl;
        }
    }
    
}
