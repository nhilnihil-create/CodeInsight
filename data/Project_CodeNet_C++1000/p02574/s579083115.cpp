#include <bits/stdc++.h>
using namespace std;
int N;
const int M=1000001;
vector<int>a[M];
bool vis[M];
int gcd(int a,int b){
    return a==0?b:gcd(b%a,a);
}

main()
{
    cin>>N;
    for(int i=2;i<M;++i)for(int j=i;j<M;j+=i)a[j].push_back(i);
    int g=0;
    bool flag=true;
    for(int i=0;i<N;++i){
        int A;cin>>A;
        g=gcd(g,A);
        for(int j:a[A]){
            flag&=!vis[j];
            vis[j]=true;
        }
    }
    if(flag){
        cout<<"pairwise coprime"<<endl;
    }else if(g==1){
        cout<<"setwise coprime"<<endl;
    }else{
        cout<<"not coprime"<<endl;
    }
}