#include <bits/stdc++.h>
using namespace std;


int main(){
 long long n,m,c=0,k,x,y,l,r,d=0,sum=0;
 cin >>n>>m>>k;
 long long a[n],b[m];
 for(long long i=0;i<n;i++){cin >>a[i];sum+=a[i];}
 for(long long i=0;i<m;i++)cin >>b[i];
 x=0;
 long long sum2=0;
 for(long long i=n;i>=0;i--){
    if(i<n)sum-=a[i];
    if(sum<=k){
        while(sum+sum2+b[x]<=k && x<m){
            sum2=sum2+b[x++];

        }
     c=max(c,i+x);
    }

 }
 cout << c << endl;
}
