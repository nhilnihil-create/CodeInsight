#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    long long int a[n];
    long long int mon=1000;
    for(int i=0;i<n;i++)cin >> a[i];
    for(int i=1;i<n;i++){
        if(a[i]>a[i-1])mon+=(mon/a[i-1])*(a[i]-a[i-1]);
    }
    cout << mon;
}