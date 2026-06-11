#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define pii pair<int,int>
#define PII pair<ll,ll>

int main()
{
    ll n,m,i,j,k,p,q,x,y,a,b,c,tot;

    cin>>x>>y>>a>>b>>c;

    vector<PII> test;

    for(i=1;i<=a;i++){
        cin>>p;
        test.push_back({p,1});
    }

    for(i=1;i<=b;i++){
        cin>>p;
        test.push_back({p,2});
    }

    for(i=1;i<=c;i++){
        cin>>p;
        test.push_back({p,3});
    }

    sort(test.begin(),test.end(),greater<PII>());

    ll r=0, g=0;
    ll siz=test.size();

    ll sum=0;
    for(i=0;i<siz && i<(x+y);i++){
        sum+=test[i].first;
        if(test[i].second==1) ++r;
        else if(test[i].second==2) ++g;
    }

    if(r<=x && g<=y){
        cout<<sum<<'\n';
        return 0;
    }

    if(r>x){
       p=i;
       --i;
       tot=(x+y);
       while(i>=0 && r>x){
          if(test[i].second==1) sum-=test[i].first, --r,--tot;
          --i;
       }

       i=p;
       while(i<=siz && tot<(x+y)){
           if(test[i].second != 1) sum+=test[i].first,++tot;
           ++i;
       }
    }

    else if(g>y)
    {
       p=i;
       --i;
       tot=(x+y);
       while(i>=0 && g>y){
          if(test[i].second==2) sum-=test[i].first, --g,--tot;
          --i;
       }

       i=p;
       while(i<=siz && tot<(x+y)){
           if(test[i].second != 2) sum+=test[i].first,++tot;
           ++i;
       }
    }

    cout<<sum<<'\n';

}
