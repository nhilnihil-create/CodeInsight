#include "bits/stdc++.h"
using namespace std;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    
    int a[n];

    for(int& i : a)cin >> i;
    
    int mx=a[0];

    long long stool=0;

    for(int i=1;i<n;i++){
        if(a[i]<mx){
            stool+=mx-a[i];
        }
        else{
            mx=a[i];
        }
    }
    cout<<stool<<endl;
}

