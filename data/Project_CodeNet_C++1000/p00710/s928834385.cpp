#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,r;

    while(cin>>n>>r,n|r){
        vector<int> v(n);

        for(int i=0; i<n;i++){
            v[i]=n-i;
        }

        for(int i=0; i<r; i++){
            int p,c;
            cin>>p>>c;

            rotate(v.begin(),v.begin()+p-1,v.begin()+p+c-1);
        }

        cout << v[0] << endl;
    }
}