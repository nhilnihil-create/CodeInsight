#include<bits/stdc++.h>
using namespace std;

int main()
{

        long long n,m,a,b,c,d,e,f,g,h,p,q,r,fr,sc,tr,sz,tz,i,j,k,mx=LLONG_MIN,mn=LLONG_MAX;
        long long x=0,y=0,cnt=0,res=0,ttl=0,ans=0,sum=0; long long flg=0,flag=1,na=0,as=1;
        vector<long long>u,v,w; vector< pair<long long,long long> >vct; vector<string>vst;
        set<long long>st,nt,tt; map<long long,long long>mp,nq,qr; string str,ttr,ntr;

        //scanf("%lld",&n);

        cin>>str;  sz=str.size();

        for(i=0;i<sz;i++)
        {
            x++; if(str[i]=='L')cnt++;

            if(str[i]=='L'&& str[i+1]=='R')
            {
                h=x/2; g=h; if(x%2==1)g=h+1; if(cnt%2==1)swap(g,h);

                for(j=y;j<=i;j++)
                {
                    if(str[j]=='R' && str[j+1]=='L' ){printf("%lld ",g);}
                    else if(str[j]=='L' && str[j-1]=='R'){printf("%lld ",h);}
                    else{  printf("0 "); }
                }

                y=i+1; x=0; cnt=0;
            }


        }

        h=x/2; g=h; if(x%2==1)g=h+1; if(cnt%2==1)swap(g,h);


        for(j=y;j<sz;j++)
        {
                if(str[j]=='R' && str[j+1]=='L' ){printf("%lld ",g);}
                else if(str[j]=='L' && str[j-1]=='R'){printf("%lld ",h);}
                else{  printf("0 "); }
        }








    return 0;
}



