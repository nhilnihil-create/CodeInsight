#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
int main(){
    long long int n,b=0;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++){
        cin >> a[i];


    }
    for(int i=0;i<n-1;i++){
        if (a[i+1]<a[i]){
            b+=a[i]-a[i+1];
            a[i+1]=a[i];
        }


    }
    cout << b << endl;



}