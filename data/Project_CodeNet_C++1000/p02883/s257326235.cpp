#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INFL 0x3f3f3f3f3f3f3f3f
const int mxN=200005;
int n,m[mxN],d[mxN],k,maior,resp;

int C(int u){
    int counter=0;
    for(int i=0;i<n;i++){
        if(m[i]*d[n-i-1]>u){
            counter+=(m[i]*d[n-i-1]-u+d[n-i-1]-1)/d[n-i-1];
            if(counter>k)return 0;
        }
    }
    return 1;

}

int bb(){
    int ini=0,fim=maior,meio;
    while(ini<=fim){
        meio=(ini+fim)/2;
        //cout<<meio<<"\n";
        if(C(meio)){
            resp=meio;
            fim=meio-1;
        }
        else ini=meio+1;

    }

    cout<<resp<<"\n";
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>m[i];
    }
    for(int i=0;i<n;i++){
        cin>>d[i];
    }
    sort(m,m+n);
    sort(d,d+n);

    for(int i=0;i<n;i++){
        maior=max(maior,m[i]*d[n-i-1]);
    }

    resp=maior;

    bb();


}