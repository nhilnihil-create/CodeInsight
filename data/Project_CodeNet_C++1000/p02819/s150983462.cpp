#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mxn= 5e5+5;
#define mod 1000000007
#define endl '\n'
void rishabh(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
int get(int n){
    if(n%2==0)return n/2;
    else return 3*n+1;
}
int main(){
    int n;
    cin>>n;
    for(int i=n;i<n+1000;i++){
        bool f=true;
        for(int j=2;j*j<=i;j++){
            if(i%j==0){
                f=false;
                break;
            }
        }
        if(f==true){
            cout<<i;
            return 0;
        }
    }
}

