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
       
      sum=0; 
        for(int i =0;i<n;i++){
                sum+=a[i];
                if( time-sum < 0 ){ 
                        if(Max<i)Max=i ;
                        break ;
                        
                } 
                int l=0,r=m-1 ;
                while(l<=r){
                        int mid =r+l ;
                        mid /=2;
                        if(v[mid]<=time-sum)l=mid+1;
                        else r=mid-1; 
                        
                }if(i+l+1>Max)Max=i+l+1 ; 
        }cout<<Max ; }
        
       
        
        
        
