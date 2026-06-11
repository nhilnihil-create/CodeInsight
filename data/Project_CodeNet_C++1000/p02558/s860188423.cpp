#include<iostream>
using namespace std;
typedef long long int ll;
#define graphsize 500007

ll parent[graphsize];

ll find(ll curr){
    if(parent[curr]!=curr){
        parent[curr] = find(parent[curr]);
        return parent[curr];
    }else{
        return parent[curr];
    }
}

void combine(ll a,ll b){
    parent[find(a)]=find(b);
}

int main(){
    for(ll i=0;i<graphsize;i++){
        parent[i]=i;
    }
    ll n,q,a,b,c,x,y;
    cin>>n>>q;
    for(ll i=0;i<q;i++){
        cin>>a>>b>>c;
        if(a==0){
            combine(b,c);
        }else{
            x=find(b);
            y=find(c);
            if(x==y){
                cout<<1<<endl;
            }else{
                cout<<0<<endl;
            }
        }
    }
}