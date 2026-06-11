#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    double x;
    if(n==1)
    {x=n;
    cout<<setprecision(12)<<x<<endl;
    }
    else if(n%2==0)
    {x=n/2*1.0/n;
    cout<<setprecision(12)<<x<<endl;
    }
    else
    {   x=(n/2+1)*1.0/n;
        cout<<setprecision(12)<<x<<endl;
    }
    
}