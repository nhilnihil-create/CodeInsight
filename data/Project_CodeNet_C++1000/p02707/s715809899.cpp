#include<bits/stdc++.h>

using namespace std;

int sum[1000000];
int main(){
    int m;
    cin >> m;
    int a;
    for(int i=2;i<=m;i++){
       cin >> a;
       sum[a]+=1;
    }   
    for(int i=1;i<=m;i++){
       cout << sum[i] << endl;
     }
    return 0;
}