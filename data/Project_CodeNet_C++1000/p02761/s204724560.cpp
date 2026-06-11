#include <bits/stdc++.h>
using namespace std;


#define ll long long
#define MOD 1000000007



int main(){
    int n;
    cin>>n;
    int m;
    cin>>m;

    vector<int> c(n,-1);

    int x,v,j=0;
    for(int i=0;i<m;i++){
        cin>>x>>v;
        if(c.at(x-1) != -1){
            if(c.at(x-1)!=v){
                j = 1;
            }
        }else c.at(x-1) = v;
    }
    if(c.at(0)==0&&n!=1)j=1;

    for(int i=0;i<n;i++){
        if(c.at(i) == -1){
            if(i==0&&n!=1)c.at(i)=1;
            else c.at(i) = 0;
        }
    }

    int ans = 0;
    int t=1;
    for(int i=n-1;i>=0;i--){
        ans += c.at(i)*t;
        t *= 10;
    }

    if(j==1){
        cout<<-1<<endl;
    }else{
        cout<<ans<<endl;
    }
}
