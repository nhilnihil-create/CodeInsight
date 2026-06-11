#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
typedef long long ll;
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};

int main(){
    ll n,a,b;cin>>n>>a>>b;
    if((b-a)%2==0) cout<<(b-a)/2<<endl;
    else{
        ll d_to1=min(a-1,b-1);
        ll d_ton=min(n-a,n-b);
        if(d_to1<d_ton){
            cout<<d_to1+1+(b-a-1)/2;
        }
        else{
            cout<<d_ton+1+(b-a-1)/2;
        }
    }
}