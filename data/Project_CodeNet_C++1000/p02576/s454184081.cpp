#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){
    int n, x, t;
    cin>>n>>x>>t;
    int val=0, time=0;
    while(val<n){
        val += x;
        time += t;
    }      
    cout<<time;
}