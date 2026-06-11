#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int n;
    while(cin>>n){
       int cnt=0;
       for(int i=1,j=n-1;i<j;i++,j--){
        cnt++;
       }
       cout<<cnt<<endl;
    }
    return 0;
}
