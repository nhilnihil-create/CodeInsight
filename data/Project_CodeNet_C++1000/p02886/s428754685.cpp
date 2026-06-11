#include<bits/stdc++.h>

using namespace std;
int main(){
    int n,d[101],i,j;
    cin >> n;
    for(int i=0; i<n; i++)
       cin >> d[i];
    int sum = 0;
    for(i=0; i<n-1; i++){
       for(j=i+1; j<n; j++){
           sum += d[i]*d[j];
       }
    }
    cout << sum << endl;
}