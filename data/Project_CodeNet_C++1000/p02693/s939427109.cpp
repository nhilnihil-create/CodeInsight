#include<bits/stdc++.h>
#define endl "\n" 
using namespace std;
#define debug(x) cout<<"The value of "<<#x<<" is "<<x<<endl;
typedef long long ll;
typedef unsigned long long ull;

int main()
{
    cin.sync_with_stdio(0); cin.tie(0); 
    int k,a,b;
    cin>>k>>a>>b;
    if(a%k==0){
        cout<<"OK"<<endl;
        return 0;
    } 
    else{
        int c=a+k-a%k;
        if(c<=b)
        cout<<"OK"<<endl;
        else 
        cout<<"NG"<<endl;
    }
}
