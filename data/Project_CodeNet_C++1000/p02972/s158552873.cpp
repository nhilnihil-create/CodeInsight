#include <bits/stdc++.h>
using namespace std ;
typedef long long ll;

int main(){
    int n;cin>>n;
    int a[n+1];
    a[0]=0;
    vector<int> v;
    for(int i=1;i<=n;i++)cin>>a[i];
    int b[n+1];
    for(int i=0;i<=n;i++)b[i]=0;

    for(int i=n;i>=1;i--){
        int mol=n/i;
        int sum=0;
        for(int j=1;j<=mol;j++){
            sum+=b[j*i];
        }
        if(sum%2!=a[i]){b[i]=1;v.push_back(i);}
    }
    cout << v.size() <<endl;
    for(int i=0;i<v.size();i++)cout << v[i]<<endl;


    
}