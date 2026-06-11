#include<bits/stdc++.h>

using namespace std;
int main(){
    int n,p,i,flag=0;
    cin >> n;
    for(i=0; i<n; i++){
      cin >> p;
      if(p!=i+1) flag++;
    }
    if(flag<=2) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}