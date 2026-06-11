#include<bits/stdc++.h>
using namespace std;

vector<long long>adj[30];

int main()
{

        long long n,m,a,b,c,d,e,f,g,h,p,q,r,fr,sc,tr,sz,tz,i,j,k,mx=LLONG_MIN,mn=LLONG_MAX;
        long long x=0,y=0,cnt=0,ans=0,res=0,ttl=0,sum=0; long long flg=0,flag=1,na=0,as=1;
        vector<long long>u,v,w; vector< pair<long long,long long> >vct; vector<string>vst;
        set<long long>st,nt,tt; map<long long,long long>mp,nq,qr; string str,ttr,ntr;


        cin>>str; cin>>ttr;  sz=str.size(); tz=ttr.size();

        for(i=0;i<sz;i++)
        {
            h=str[i]-97; adj[h].push_back(i);

        }

        e=-1; vector<long long>::iterator it;

        for(i=0;i<tz;i++)
        {

            h=ttr[i]-97; r=adj[h].size();

            if(r==0){  printf("-1\n"); flag=0; break;  }


            it=upper_bound(adj[h].begin(),adj[h].end(),e); sc=it-adj[h].begin();

            if(sc==r){  ans=ans+sz; e=-1; i--;  }
            else{ fr=adj[h][sc];  e=fr;  if(i==tz-1){  ans=ans+fr; ans++;  }     }



        }


        if(flag==1)printf("%lld\n",ans);




    return 0;
}



