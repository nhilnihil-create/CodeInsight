#include<bits/stdc++.h> 
using namespace std;
using ll = long long;

#define fast_io ios_base::sync_with_stdio(false) ; cin.tie(0); cout.tie(0);

int main() {
    fast_io;

    int a,b,c,d;
    cin>>a>>b>>c>>d;

    int round=1;

    while(a>0&&c>0) {
        if(round%2==1) {
            c-=b;
        }
        else {
            a-=d;
        }
        round++;
    }

    if(c<=0) {
        cout<<"Yes"<<endl;
    }
    else {
        cout<<"No"<<endl;
    }


}


