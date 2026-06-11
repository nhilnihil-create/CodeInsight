#include<bits/stdc++.h>
using namespace std;

struct data
{
    long long prop,sum;
}  tree[524924]   ;

long long ara[200002];

/*void build(long long nd,long long l,long long r)
{
    if(l==r)
    {
        tree[nd]=ara[l];
    }
    else
    {
        long long lt,rt,md; lt=nd<<1; rt=lt+1;  md=(l+r)>>1;

        build(lt,l,md); build(rt,md+1,r);

        tree[nd]=max(tree[lt],tree[rt]);


    }

}*/

long long query(long long nd,long long l,long long r,long long x,long long y,long long car)
{

     if(l>y || r<x)return 0;
     else if(l>=x && r<=y)
     {
         return tree[nd].sum+(r-l+1)*car;
     }
     else
     {

         long long lt,rt,md,fq,sq; lt=nd<<1; rt=lt+1; md=(l+r)>>1;

         fq=query(lt,l,md,x,y,car+tree[nd].prop); sq=query(rt,md+1,r,x,y,car+tree[nd].prop);

         return fq+sq;

     }


}

void update(long long nd,long long l,long long r,long long x,long long y,long long val)
{

     if(l>y || r<x)return;
     else if(l>=x && r<=y)
     {
         tree[nd].sum+=(r-l+1)*val;
         tree[nd].prop+=val;
         return;

     }
     else
     {

         long long lt,rt,md; lt=nd<<1; rt=lt+1; md=(l+r)>>1;

         update(lt,l,md,x,y,val); update(rt,md+1,r,x,y,val);

         tree[nd].sum=tree[lt].sum+tree[rt].sum+(r-l+1)*tree[nd].prop;


     }


}

int main()
{


        long long n,m,a,b,c,d,e,f,g,h,p,q,r,fr,sc,tr,sz,tz,i,j,k,mx=LLONG_MIN,mn=LLONG_MAX;
        long long x,y,z,cnt=0,res=0,ttl=0,ans=0,sum=0; long long flg=0,flag=1,na=0,as=1;
        vector<long long>u,v,w; vector< pair<long long,long long> >vct; vector<string>vst;
        set<long long>st,nt,tt; map<long long,long long>mp,nq,qr; string str,ttr,ntr;

        scanf("%lld %lld %lld",&n,&d,&a); m=d*2;

        for(i=0;i<n;i++)
        {

            scanf("%lld %lld",&p,&r); q=r/a; if(r%a!=0)q++;
            vct.push_back(make_pair(p,q));
            v.push_back(p);

        }

        sort(vct.begin(),vct.end());  sort(v.begin(),v.end());

        /*for(i=0;i<n;i++)
        {
            q=vct[i].second; ara[i+1]=q;

        }

        build(1,1,n);*/

        vector<long long>::iterator it;

        for(i=0;i<n;i++)
        {
            p=vct[i].first; q=vct[i].second;

            z=query(1,1,n,i+1,i+1,0); //cout<<i+1<<" "<<q<<"      "<<z<<endl;

            h=max(0LL,q-z); ans=ans+h;  if(i==n-1)break;

            e=p+m;  it=upper_bound(v.begin(),v.end(),e); g=it-v.begin(); g--;

            if(g!=i)
            {
                //cout<<i+2<<" "<<g+1<<"    "<<h<<endl;

                update(1,1,n,i+2,g+1,h);

            }



        }


        printf("%lld\n",ans);







    return 0;
}



