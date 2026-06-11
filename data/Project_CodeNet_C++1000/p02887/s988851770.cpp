#include<bits/stdc++.h>
using namespace std;
int main(){
    int n; 
    cin>>n;
     char c[n];int ans =1;
     cin>>c[0];
     for(int i=1;i<n;i++){cin>>c[i];if(c[i]!=c[i-1])ans++;}cout<<ans;
}