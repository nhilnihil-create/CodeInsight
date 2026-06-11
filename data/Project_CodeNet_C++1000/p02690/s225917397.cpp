/*
Sharif Hasan - CSE, PUST
Apr 24, 2020 02: 14 PM
*/
#include<bits/stdc++.h>
#define br cout<<"\n"
#define what(x) cout<<"in here var= "<<x<<"\n";

/*STL definations*/
#define pb push_back

#define FOR(i,n) for(long long i=0;i<n;i++)
#define FROM(a,i,n) for(long long i=a;i<n;i++)
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;
/*Main function*/
int main()
{
    long long x;
    cin>>x;
    long long k=pow(x,1/5.0)+1000;
   // cout<<k<<endl;
    for(long long i=-k-2;i<=k+2;i++){
       // cout<<i;br;
        long long k=-(x-pow(i,5));
        long long tmp=k;

        k=pow(abs(k),1/5.0);
        
        k=k*(tmp/abs(tmp));
        
        if(pow(i,5)-pow(k,5)==x){
            cout<<i<<" "<<k;br;
            break;
        }
    }
    
    
}
