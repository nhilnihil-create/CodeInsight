#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int testcase=1;
    //cin>>testcase;
    for(int p=0;p<testcase;p++){
        ll n=0;
        cin>>n;
        float array[n]={0};
        for(int i=0;i<n;i++){
            cin>>array[i];
        }
        sort(array,array+n);
        float sum=(array[0]+array[1])/2;
        for(int i=2;i<n;i++){
            sum+=array[i];
            sum=sum/2;
        }
        cout<<sum;
        
        
    }

    return 0;
}
