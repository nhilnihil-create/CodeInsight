#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <stdlib.h>
using namespace std;

#define INF 1e9
#define PI 3.141592653589793238
typedef long long ll;

int main() {
    int a[3][3], n, b, flag=0;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            cin>>a[i][j];
        }
    }
    cin>>n;
    for(int k=0; k<n; k++){
        cin>>b;
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                if(a[i][j]==b) a[i][j]=0;
            }
        }
    }

    if(a[0][0]+a[0][1]+a[0][2]==0) flag=1;
    else if(a[1][0]+a[1][1]+a[1][2]==0) flag=1;
    else if(a[2][0]+a[2][1]+a[2][2]==0) flag=1;
    else if(a[0][0]+a[1][0]+a[2][0]==0) flag=1;
    else if(a[0][1]+a[1][1]+a[2][1]==0) flag=1;
    else if(a[0][2]+a[1][2]+a[2][2]==0) flag=1;
    else if(a[0][0]+a[1][1]+a[2][2]==0) flag=1;
    else if(a[0][2]+a[1][1]+a[2][0]==0) flag=1;

    if(flag==1) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;

    return 0;
}