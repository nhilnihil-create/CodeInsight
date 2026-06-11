#include<bits/stdc++.h>
#define rep(i,N) for(int i=0;i<N;i++)
using namespace std;
typedef long long ll;

int main(){
int n,k,q;
cin>>n>>k>>q;
vector<int>a(n);
rep(i,q){
    int b;
    cin>>b;
    a[b-1]++;
}
rep(i,n){
if(k-q+a[i]>0){
   cout<<"Yes"<<endl;
}
else{
   cout<<"No"<<endl;
}
}

}