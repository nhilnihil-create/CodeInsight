#include <iostream>
#include<vector>
#include<map>
#include<cmath>
#include<iomanip>
#define ll long long
using namespace std;
#define rep(n) for(int i=0;i<n;i++)
#define rep2(a,n) for(int i=a;i<=n;i++)
int main(void){
    // Your code here!
int n,k,q;
cin>>n>>k>>q;
map<int,int> mp;
rep(q){
    int a;
    cin>>a;
    mp[a]++;
}

rep2(1,n){
    if((k-(q-mp[i]))>0)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
}

}
