#include <bits/stdc++.h>
#define ll  long long int
#define out  cout<<

using namespace std;



int main(){
    ll n;
    cin>>n;
    ll a[n][n];

    for(ll i=0;i<n;i++){
     for(ll j=0;j<2;j++){
        cin>>a[i][j];

     }

    }
    //for(ll i=0;i<n;i++)
       // cout<<indx[i]<<"\n";
    bool flag =false;
       for(ll k=0;k<n-2;k++){
            if((a[k][0] ==a[k][1])&&(a[k+1][0]  == a[k+1][1])&&(a[k+2][0]  == a[k+2][1])){
                flag =true;
                break;
            }


       }
       if(flag == true)
        cout<<"Yes"<<"\n";
       else
        cout<<"No"<<"\n";

return 0;}
