#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <stdlib.h>
using namespace std;

#define INF 1e9
#define PI 3.141592653589793238
typedef long long ll;

int main() {
    int n;cin>>n;
    int a, flag=0;
    for(int i=0; i<n; i++){
        cin>>a;
        if(a%2==0){
            if(a%3!=0 && a%5!=0) flag=1;
        }
    }

    if(flag==0)cout<<"APPROVED"<<endl;
    else cout<<"DENIED"<<endl;

    return 0;
}