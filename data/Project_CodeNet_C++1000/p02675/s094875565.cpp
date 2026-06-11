#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define see(x) cout<< #x <<" = "<< x <<' ';
#define seen(x) cout<< #x <<" = "<< x <<'\n';
#define UWU cout<<'\n';
int main(){
//ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;cin>>n;
    n%=10;
    if(n == 3){
        cout<<"bon";
    }else if(n == 0 || n == 1 || n == 6 || n == 8){
        cout<<"pon";
    }else cout<<"hon";
}
