#include<bits/stdc++.h>

using namespace std;
int main(){
    int n,m;
    cin >> n >> m;
    int a,sum=0;
    for(int i=0;i<m;i++){
       cin >> a;
       sum+=a;
    }   
    if(n>=sum) cout << n-sum << endl;
    else cout << "-1" << endl;
    return 0;
}