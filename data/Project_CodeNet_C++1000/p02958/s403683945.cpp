#include <bits/stdc++.h>
using namespace std ;
typedef long long ll;

int main(){
    int N;cin>>N;
    int p[N],a[N];
    for(int i=0;i<N;i++){
        cin>>p[i];
        a[i]=p[i];
    }

    sort(p,p+N);
    int count=0;
    for(int i=0;i<N;i++){
        if(a[i]!=p[i])count++;
    }


    if(count==2||count==0)cout<<"YES";
    else cout<<"NO";

}