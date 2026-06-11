#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >>n;

    int cnt=0;
    for(int i=0;i<n;i++){
        int x,y;
        cin >>x>>y;
        if(x==y)cnt++;
        else cnt=0;
        if(cnt>=3){
            cout<<"Yes"<<endl;
            return 0;
        }
    }
    cout<<"No"<<endl;
}


