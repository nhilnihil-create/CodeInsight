#include <iostream>
#include<bits/stdc++.h>
using namespace std;
long long cum [ 100001];

int main(){
        int n , m ,time ; 
        cin>>n>>m>>time ; 
        int a[n],b[m];
        for(int i =0;i<n;i++)cin>>a[i];
        for(int i =0;i<m;i++)cin>>b[i];
        vector<long long> v ; 
        long long sum = 0 , Max=0 ; 
        for(int i =0;i<m;i++){
                sum+=b[i];
                if(sum<=time)Max=i +1; 
                v.push_back(sum);
        }
       
        long long int M=m-1;
        sum=0; 
        for(int i =0;i<n;i++){
                sum+=a[i]; 
                if(sum>time){
                        Max = max(1ll*i,Max ) ; 
                        break ;} 
                if(sum==time){
                          Max = max(1ll*i+1,Max ) ; 
                        break ;
                }   
                while(M>=0){
                        if(sum+v[M]<=time){
                        
                                Max=max(Max,i+M+2);
                                        break;
                                
                        }
                        
                 M-- ;}
              //  cout<<sum+v[M]<<" "; 
                
        }cout<<Max ;  
        
        
}