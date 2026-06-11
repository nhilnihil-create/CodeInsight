#include "bits/stdc++.h"
#include <random>
using namespace std;
 

bool check(int x, int y ,int z){
    int a[3];
    a[0]=x,a[1]=y,a[2]=z;
    sort(a,a+3);
    return (a[0]+a[1]>a[2]) &&(a[0]!=a[1] && a[1]!=a[2]);
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    int a[n];
    for(int& i : a)cin >>i;

    int cnt=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                if(check(a[i],a[j],a[k])){
                   cnt++; 
                }
            }
        }
    }
    cout<<cnt<<endl;
}

