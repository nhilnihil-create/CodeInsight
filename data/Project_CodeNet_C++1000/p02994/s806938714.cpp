#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     int t;
    //cin>>t;
     t=1;
     while(t--)
     {

        long long int n,k;
        cin>>n>>k;
        long long int R=n+k-1,L=k;
 int eat;
 if(R<=0)eat=R;
 else if(L>=0)eat=L;
 else eat=0;
 
 int answer=(R+L)*(R-L+1)/2-eat; 
 cout<<answer<<endl;
     }
}
