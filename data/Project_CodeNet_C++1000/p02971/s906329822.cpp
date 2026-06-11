#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n),b(n);
    for(int i=0;i<n;i++){
        cin >> a.at(i);
        b.at(i)=a.at(i);
    }
    sort(b.begin(),b.end());
    for(int i=0;i<n;i++){
        if(b.at(n-1)!=a.at(i))cout << b.at(n-1) << endl;
        else cout << b.at(n-2) << endl;
    }
    return 0;
}