#include <bits/stdc++.h>

using namespace std;

int main() {

    int n,m,x;
    cin>>n>>m;
    while(m--){
        cin>>x;
        n-=x;
    }
    n<=0?cout<<"Yes"<<endl:cout<<"No"<<endl;

    return 0;
}
