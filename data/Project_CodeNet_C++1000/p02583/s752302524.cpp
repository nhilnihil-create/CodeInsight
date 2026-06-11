#include<bits/stdc++.h>
using namespace std;
#define N 100010
#define ll long long
int fun(int a,int b,int c){
    if(a != b && a != c && b != c){
        if(a<b+c && b<a+c && c<a+b){
            return 1;
        }
    }
    return 0;
}
int main()
{
    int ans = 0;
    int n;
    cin>>n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin>>a[i];
    }
    for(int i = 0; i < n-2; i++){
        for(int j = i+1; j < n-1; j++){
            for(int k = j+1; k < n; k++){
                ans += fun(a[i],a[j],a[k]);
            }
        }
    }
    cout<<ans;
    return 0;
}
