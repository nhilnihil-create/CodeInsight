#include <iostream>
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using dl = long double;
int main()
{
    dl n;
    cin>>n;
    vector<dl>x(n),y(n);
    for(int i=0;i<n;i++){
        cin>>x[i]>>y[i];
    }
    dl z=1;
    dl p=n-2;

    while(p>0){
        z*=p;
        p--;
    }
    dl space = n-2+1;

    //cout<<z<<endl;

    dl ans=0;
    for(int i=0;i<n;i++){
            dl sum=0;
        for(int j=i+1;j<n;j++){
            if(i!=j){
              sum=sqrt(((x[i]-x[j])*(x[i]-x[j]))+((y[i]-y[j])*(y[i]-y[j])))  ;
                sum*=z;
                sum*=space*2;
                ans+=sum;
                //cout<<ans<<endl;
            }
        }
    }



   dl m = z*(n-1)*n;
  // cout<<m<<endl;
   cout<<fixed <<setprecision(10)<<(ans/m)<<endl;



    return 0;
}
