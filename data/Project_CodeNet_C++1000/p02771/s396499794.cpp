#include <bits/stdc++.h>
using namespace std;
bool T=false;
void solve(){
    vector<long long> A(3);
    for (int i = 0; i < 3; i++)
    {
        cin>>A[i];
    }
    bool T=false;
    sort(A.begin(),A.end());
    if(A[0]==A[1]&&A[1]!=A[2])T=true;
    reverse(A.begin(),A.end());
    if(A[0]==A[1]&&A[1]!=A[2])T=true;
    if(T)cout<<"Yes";
    else cout<<"No";
}

int main(){
    solve();
    cout<<endl;
}