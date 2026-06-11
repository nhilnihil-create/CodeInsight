#include <bits/stdc++.h>
using namespace std;
int main() {
    int a[3];
    cin>>a[0]>>a[1]>>a[2];
    int k;
    cin>>k;
    
    for(int i=1;i<3;){
        if(a[i-1]<a[i]){
            i++;
            continue;
        }
        if(k==0){
            break;
        }
        a[i] = a[i]*2;
        k--;
    }
    for(int i=1;i<3;i++){
        if(a[i-1]>=a[i]){
            cout<<"No\n";
            return 0;
        }
    }
    cout<<"Yes";
}
