#include <iostream>
#include<bits/stdc++.h>
using namespace std;
long long  div1[10000001];
int main()
{
        for( int i =2;i<10000001;i++){
                for(int j = i;j<10000001;j+=i){
                        div1[j]++ ; 
                }
        }
        
        int n ; 
        cin>>n;
      //  div1[10000000]++ ; 
        
        long long sum =0 ; 
        for(int i =1;i<=n;i++){
                sum+=i*(div1[i]+1);
        }cout<<sum ; 
}