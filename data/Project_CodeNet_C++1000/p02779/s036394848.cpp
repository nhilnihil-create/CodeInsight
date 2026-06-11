#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
    set<int> s;
    int N;cin>>N;
    for (int i = 0; i < N; i++){
        int a;cin>>a;
        if(s.count(a)){
            cout<<"NO"<<endl;
            return 0;
        }
        s.insert(a);
    }
    cout<<"YES"<<endl;
}