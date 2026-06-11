#include <bits/stdc++.h>
using namespace std;
using vi=vector<int>;
int main() {
    int N; cin>>N;
    int neq=0;
    for (int i = 0; i < N; i++){
        int p;cin>>p;
        if(p!=i+1)neq++;
    }
    if(neq<=2)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}