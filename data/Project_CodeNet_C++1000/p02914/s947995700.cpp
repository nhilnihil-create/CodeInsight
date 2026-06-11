#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;
const int MAXL = 60;
ll tot;
struct LinearBasis{
    ll a[MAXL + 1];
    LinearBasis(){
        std::fill(a,a+MAXL+1,0);
    }
    void insert(ll t){
        for(int j=MAXL;j>=0;--j){
            if(!(t&(1ll<<j)))   continue;
            if(a[j])    t^=a[j];
            else{
                for(int k=0;k<j;++k)    if(t&(1ll<<k))  t^=a[k];
                for(int k=j+1;k<=MAXL;++k)  if(a[k]&(1ll<<j))   a[k]^=t;
                a[j]=t;
                return;
            }
        }
    }
    void PRINT(){
        cout<<"=========="<<endl;
        for(int j=MAXL;j>=0;--j)
            if(a[j])
                cout<<1;
            else cout<<0;
        cout<<endl<<"^^^^^^^^^^"<<endl;
    }
};
const int maxn = 100000+10;
ll a[maxn];
int main()
{
    int N;
    cin>>N;
    for(int i=0;i<N;++i)    cin>>a[i];
    for(int i=0;i<N;++i)    tot^=a[i];
    for(int i=0;i<N;++i)
        a[i]&=~(tot);
    LinearBasis LB;
    for(int i=0;i<N;++i)
        LB.insert(a[i]);
    ll ans=0;
    for(int j=0;j<=MAXL;++j)
        ans^=LB.a[j];
    //LB.PRINT();
    cout<<tot+ans*2<<endl;
    return 0;
}
