#include <bits/stdc++.h>
using namespace std;
 
int main(){
    long long int n,k=1,a[100001];
    cin >> n;
    for (int i=0;i<n;i++){
        cin >> a[i];
        if(a[i]==0){
            k=0;
            break;
        }
        if(k>1000000000000000000/a[i]||k==-1){
            k=-1;
        }else{
          k*=a[i];
        }
    }
    cout << k;
  return 0;
}