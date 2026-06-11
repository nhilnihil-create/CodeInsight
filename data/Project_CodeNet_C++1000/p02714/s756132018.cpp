#include <bits/stdc++.h>
#define simplify ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
#define endl "\n"
using namespace std;


int32_t main(){

    simplify

    int n;
    cin>>n;

    string s;
    vector<int>arr(n);
    cin>>s;

    int r,g,b;
    r=g=b=0;

    for(int i=0;i<n;i++){
        if(s[i]=='R'){
            arr[i]=1; r++;
        }
        else if(s[i]=='G'){
            arr[i]=2; g++;
        }
        else{
            arr[i]=5; b++;
        }
    }

    int total=r*g*b;
    int substract=0;
    int sum;
    for(int gap=1;gap<n;gap++){
        for(int i=0;i<n;i++){
            if(i+gap>=n)break;
            if(arr[i]+arr[i+gap]+arr[i+2*gap]==8)substract++;

        }
    }
    total-=substract;
    cout<<total;





    
    return 0;
}
