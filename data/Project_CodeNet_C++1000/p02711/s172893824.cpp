#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int n;
    cin>>n;

    while(n>0){
        int t = n%10;
        if(t == 7){
            cout<<"Yes";
            return 0;
        }
        n/=10;
    }
    cout<<"No";
}
