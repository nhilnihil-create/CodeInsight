#include<bits/stdc++.h>

using namespace std;
int main(){
    int n,a,i,count=0;
    cin >> n;
    for(i=1; i<=n; i++){
       cin >> a;
       if(i%2==1 && a%2==1)
         count++;
    } 
    cout << count << endl;
    return 0;
}