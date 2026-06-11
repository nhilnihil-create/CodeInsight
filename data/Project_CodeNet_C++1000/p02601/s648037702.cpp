#include<bits/stdc++.h>
using namespace std;

int main(){
    int a,b,c,k; cin >> a >> b >> c >> k;
    for (int i=0; i<k; i++){
        if(a>=b) b=2*b;
        else c=2*c;
    }
    if(a<b && b<c) cout << "Yes" << endl;
    else cout << "No" << endl;
}