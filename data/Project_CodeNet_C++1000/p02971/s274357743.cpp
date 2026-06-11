#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,saidai=0;
    cin >> n;
    vector<int> a(n);
    for (int i=0;i<n;i++){
        cin>>a.at(i);
    }
    int b=0;
    for(int i=0;i<n;i++){
        b=max(b,a[i]);
    }
    int c=0,d=0;
    for(int i=0;i<n;i++){
        if(a[i]==b){
            if(d)
            c=max(c,a[i]);
            else
            d=1;
        }
        else
        c=max(c,a[i]);
    }
    for(int i=0;i<n;i++){
        if(b==a.at(i)){
            cout<<c<<endl;
        }else{
            cout<<b<<endl;
        }
    }
    
}
