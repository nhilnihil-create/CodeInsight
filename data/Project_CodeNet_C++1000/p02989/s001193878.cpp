#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int testcase=1;
    //cin>>testcase;
    for(int p=0;p<testcase;p++){
     ll n=0;
     cin>>n;
     int array[n]={0};
     for(int i=0;i<n;i++)
     cin>>array[i];
     sort(array,array+n);
    cout<<array[n/2]-array[n/2-1];
   
    }

    return 0;
}
