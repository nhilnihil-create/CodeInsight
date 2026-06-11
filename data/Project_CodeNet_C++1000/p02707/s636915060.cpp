#include<bits/stdc++.h> 
using namespace std;
using ll = long long;

#define fast_io ios_base::sync_with_stdio(false) ; cin.tie(0); cout.tie(0);

int main() {
    fast_io;
    map<int,int> m;

    int n;
    cin>>n;

    for(int i=1;i<=n;i++) {
        m[i]=0;
    }

    for(int i=1;i<n;i++) {
        int num;
        cin>>num;
        m[num]++;
    }

    map<int,int>::iterator it;
    for(it=m.begin();it!=m.end();it++) {
        cout<<it->second<<endl;
    }


}


