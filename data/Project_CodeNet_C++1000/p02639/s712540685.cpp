#include<bits/stdc++.h> 
using namespace std;

#define fast_io ios_base::sync_with_stdio(false) ; cin.tie(0); cout.tie(0);

int main() {
    fast_io;
    int pos=1;

    int num;
    while(cin>>num) {
        if(num==0) {
            cout<<pos<<endl;
            return 0;
        }
        pos++;
    }
}


