#include <bits/stdc++.h>
using namespace std;
typedef long long int ll; // int -> ll

int main(){
    ll a,v,b,w,t;
    cin >>a>>v>>b>>w>>t;
    if(abs(a-b) <= (v-w)*t){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" <<endl;
    }
}
