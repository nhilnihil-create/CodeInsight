#include <bits/stdc++.h>
using namespace std;
int N;
const int M=1000001;
int cnt[M];
int gcd(int a,int b){return a?gcd(b%a,a):b;}

main()
{
    cin>>N;
    int g=0;
    bool ok=true;
    for(int i=0;i<N;++i){
        int A;cin>>A;
        g=gcd(g,A);
        ++cnt[A];
    }
    for(int i=2;i<M;++i){
        int s=0;
        for(int j=i;j<M;j+=i)s+=cnt[j];
        if(s>1)ok=false;
    }
    cout<<(ok?"pairwise coprime":g==1?"setwise coprime":"not coprime")<<endl;
}