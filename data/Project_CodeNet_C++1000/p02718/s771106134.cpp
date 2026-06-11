#include <bits/stdc++.h>
using namespace std;
#define fo(i,n) for(int i=0;i<n;i++)
int main(){
    int n,m,cnt =0;
    double sum =0;
    cin >> n>>m;
    int arr[n];
    fo(i,n){
        cin >> arr[i];
        sum += arr[i];
    }
    sort(arr, arr+n ,greater<int>());
    sum = (sum)/(4*m);
    fo(i,n){
        if(arr[i]>=sum){
            ++cnt;
        }
        if(cnt==m){
            break;
        }
    } 
    if(cnt==m){
        cout <<"Yes";
    }   
    else{
        cout << "No";
    }
}