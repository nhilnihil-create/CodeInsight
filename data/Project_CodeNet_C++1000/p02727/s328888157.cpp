#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
ll apple[3*N];
bool cmp(ll a,ll b){
    return a>b;
}
int main(){
    int x,y,a,b,c;
    cin>>x>>y>>a>>b>>c;
    for(int i=0;i<a;i++){
        cin>>apple[i];
    }
    sort(apple,apple+a,cmp);
    for(int i=x;i<x+b;i++){
        cin>>apple[i];
    }
    sort(apple+x,apple+x+b,cmp);
    for(int i=x+y;i<x+y+c;i++){
        cin>>apple[i];
    }
    sort(apple,apple+x+y+c,cmp);
    ll sum=0;
    for(int i=0;i<x+y;i++) sum+=apple[i];
    cout<<sum<<endl;
}
