#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
    int H,N;cin>>H>>N;
    for (int i = 0; i < N; i++){
        int A;cin>>A;
        H-=A;
    }
    if(H<=0)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}