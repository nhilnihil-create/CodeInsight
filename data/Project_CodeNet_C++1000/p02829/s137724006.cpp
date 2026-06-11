#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
const ll INF = 1LL<<60;
/////////////////////////////////
int main(){
    int a,b,c;
    cin>>a>>b;
    if(a==1){
        if(b==2)
            c = 3;
        else
            c = 2;
    }
    else if(a==2){
        if(b==1)
            c = 3;
        else
            c = 1;
    }
    else{
        if(b==1)
            c = 2;
        else
            c = 1;
    }
    cout << c << endl;
}