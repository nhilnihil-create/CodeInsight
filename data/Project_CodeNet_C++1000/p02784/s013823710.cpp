#include<bits/stdc++.h>
using namespace std;
int main(){
    long h,n;
    cin >> h >> n;
    long a[n];
    long summ = 0;
    for(int i=0;i<n;i++){
        cin >> a[i];
        summ += a[i];
    }
    if( h <= summ)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;

}