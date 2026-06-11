#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
   long long int c[10][10]={0},sum=0;
   long long int n;
    cin>>n;
    for(long long int i=1;i<=n;i++){
       long long int a=i;
        long long int b=a%10;
        while(a>=10){
            a/=10;
        }
        c[a][b]++;
    }
    for(long long int i=0;i<=9;i++){
        for(long long int j=0;j<=9;j++){
            sum+=(c[i][j]*c[j][i]);
        }
    }
    cout<<sum<<endl;
}