#include<bits/stdc++.h>
using  namespace std;

main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long i,j,k,l,m,n,o,p;
 while(cin>>p){
    int x[p],y[p];
    for(i=0;i<p;i++){
        cin>>x[i]>>y[i];
    }
    j=0,l=0;
    for(i=0;i<p;i++){
        if(x[i]==y[i])j++;
        else j=0;
        if(j>=3)l++;
    }
    if(l>0)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
 }
    return 0;
}
