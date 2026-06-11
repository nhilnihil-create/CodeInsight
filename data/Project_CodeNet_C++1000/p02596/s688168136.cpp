    #include<bits/stdc++.h>
    using namespace std;
    #define ll long long
    int main(){
    ll int x;
     cin>>x;
     if(x%2==0){
         cout<<"-1"<<endl;
     }
     else{
     int a=7;
    // ll b=x;
     int flag=0;
     for(ll i=1; i<=(ll)1e7;i++){
         if(a%x==0){
             cout<<i;
             flag=1;
             break;}
              a=((a*10)%x +7)%x;
         }
         if(flag==0){
             cout<<-1;}

         
     }

     }

        
        
    