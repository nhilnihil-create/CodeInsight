#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int testcase=1;
    //cin>>testcase;
    for(int p=0;p<testcase;p++){
      float x1=0,x2=0;
      double n=0;
      cin>>n;
      x1=ceil(n*100/108);
      x2=floor(n*100/108);
      if(floor(x1*1.08)==n )
      cout<<x1<<"\n";
      else if(floor(x2*1.08)==n)
      cout<<x2<<"\n";
      else
      cout<<":("<<"\n";
        
    }

    return 0;
}
