#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0; i<int(n); i++)
int main() {
    int N;
    cin>>N;
    string S;
    cin>>S;
    for(int i=0; i<S.size(); i++){
        int num=S[i]-'A';
    num=(num+N)%26;
    S[i]=num+'A';
    cout << S[i];
    }
    cout<<""<<endl;
}
