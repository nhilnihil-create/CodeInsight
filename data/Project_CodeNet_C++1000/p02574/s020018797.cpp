#include<bits/stdc++.h>
using namespace std ; 
const int N= 2e6;
long long prime [N];
int freq[N];
bool seive (){
       
        for(int i =2 ;i<=1e6;i++){
                //if(freq[i]>1)return false ;
                if(!prime[i]){
                        int c=0;
                        for(int j=i;j<=1e6;j+=i){
                                
                                prime [j]++ ; 
                                if(freq[j] ){
                                        if(c)return false ; 
                                        else c =1 ; 
                                }if(freq[j]>1)return false ;
                        }
                }
        }
        return true ; 
}
int main(){
      int n,c=1 ; 
      cin>>n ; 
      int arr[n];
      int gcd =0; 
      for(int i =0;i<n;i++){
              cin>>arr[i];
              freq[arr[i]]++; 
             // if(freq[arr[i]]>1)c=0;
              gcd=__gcd(gcd,arr[i]);
      }
      if(gcd==1 ){
             
              if(seive())
                 cout<<"pairwise coprime";
              else cout<<"setwise coprime";
      }else cout<<"not coprime";
      
}