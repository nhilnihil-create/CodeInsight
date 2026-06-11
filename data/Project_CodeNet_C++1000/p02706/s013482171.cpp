#include <bits/stdc++.h>
using namespace std;


#define ll long long
#define MOD 1000000007
#define PI 3.1415


int main(){
    int n,m;
    cin>>n>>m;
    int sum=0;

    int a;
    for(int i=0;i<m;i++){
        cin>>a;sum+=a;
    }

    if(sum<=n)cout<<n-sum<<endl;
    else cout<<-1<<endl;




}

