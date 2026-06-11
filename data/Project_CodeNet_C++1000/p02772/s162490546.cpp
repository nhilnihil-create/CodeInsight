#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0; i<int(n); i++)
int main() {
    int N;
    cin>>N;
    vector<int>A(N);
    bool a=true;
    rep(i,N){
        cin>>A.at(i);
        if(A.at(i)%2==0){
            if(A.at(i)%3==0||A.at(i)%5==0){
            }
            else{
                a=false;
            }
        }
    }
    if(a==true){
        cout<<"APPROVED"<<endl;
    }
    else
    cout<<"DENIED"<<endl;
}
