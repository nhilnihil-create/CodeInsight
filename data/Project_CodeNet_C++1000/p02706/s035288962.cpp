#include <bits/stdc++.h>
using namespace std;
#define fo(i,n) for(int i=0;i<n;i++)
int main(){
    int n,m;
    cin >>n >>m;
    fo(i,m){
        int temp;
        cin >>temp;
        n -= temp;
    }
    if(n>=0){
        cout<< n;
    }
    else{
        cout << -1;
    }
}