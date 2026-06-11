#include<bits/stdc++.h>
using namespace std;
int fact(long long int n){
    int c=0;
    for(int i=2;i<=sqrt(n);i++)
    {
        if(n%i==0)
        {
            c++;
            n/=i;
        }
    }
    if(n>1)
        c++;
    return c;
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int n;
  cin>>n;
  long long int th=0;
    if(n>=500){
  long long int fh=n/500;
    n%=500;
   th+=(1000*fh);
    }
  long long int f=n/5;
    th+=(5*f);
    cout<<th;
}
