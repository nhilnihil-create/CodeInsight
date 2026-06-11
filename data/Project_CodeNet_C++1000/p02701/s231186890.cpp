#include <bits/stdc++.h>
using namespace std;
set<string>s;
string t;
long long n;

int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>t;
        s.insert(t);

    }
    cout<<s.size();

    return 0;}