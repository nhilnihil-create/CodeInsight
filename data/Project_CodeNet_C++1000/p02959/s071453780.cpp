#include<bits/stdc++.h>
#include<string>
typedef long long ll;
#define  fi0(i,n)  for(size_t i=0;i<n;i++)
#define  vi         vector<int>
#define   vl        vector<ll>
#define   pb()    push_back()
#define   mk()    make_pair()
#define   fst      first
#define   scnd    second
#define   fast    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define   endl     '\n';
using namespace std;
void mum(){

}
void f(){

 }
void ff(){

}
int I[2][2]={1,0,0,1};
int a[1][2]={0,1};
int b[2][2]={0,1,1,1};
ll fun(int a[][2],int b[][2])
{
    for(int i=0;i<1;i++){
        for(int j=0;j<2;j++){
            for(int k=0;k<2;k++){

            }
        }
    }
}
void fff(){
     ll n,k;cin>>n>>k;
        ll a[n];
        fi0(i,n)cin>>a[i];
       for(int i=0;i<n;i++){
            for(int j=0;j<n-1;j++){
                if(a[j]<a[j+1]){
                    swap(a[j],a[j+1]);
                    k--;
                }
                if(k==0)break;
            }
            if(k==0)break;
       }
       fi0(i,n)cout<<a[i];
       cout<<endl;
}
int main()
{
    fast;
    int n;cin>>n;
    vl a(n+1),b(n);
    fi0(i,n+1)cin>>a[i];
    fi0(i,n)cin>>b[i];
    ll sum=0;
    for(int i=0;i<n;i++){
        if(a[i]<=b[i]){
            b[i]-=a[i];
            sum+=a[i];
            a[i]=0;
        }
        else {
            sum+=b[i];
            b[i]=0;
        }
        if(b[i]){
             if(a[i+1]<=b[i]){
            b[i]-=a[i+1];
            sum+=a[i+1];
            a[i+1]=0;
        }
        else {
            sum+=b[i];
        a[i+1]-=b[i];
            b[i]=0;
        }
    }
}
cout<<sum<<endl;
}

