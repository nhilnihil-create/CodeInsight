#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N;
    set<ll> A;
    cin>>N;
    for(int i=0;i<N;i++){
        ll temp;
        cin>>temp;
        A.insert(temp);
    }
    if(N==A.size()) cout<<"YES";
    else cout<<"NO";
    return 0;
}