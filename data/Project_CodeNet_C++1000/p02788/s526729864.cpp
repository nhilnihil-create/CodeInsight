///Bismillahir Rahmanir Rahim
#include<bits/stdc++.h>

#define                           int                         long long
#define                           fi                          first
#define                           si                          second
#define                           mp                          make_pair
#define                           pb                          push_back
#define                           pi                          pair<int,int>
#define                           f(i,l,r)                    for(int i=l;i<=r;i++)
#define                           rf(i,r,l)                   for(int i=r;i>=l;i--)
#define                           done(i)                     cout<<"done = "<<i<<endl;
#define                           fast                        ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);




using namespace std;

const int inf=1e18;
const int mod=1e9+7;
const int M=200009;
inline int bigmod(int B,int P){int R=1;while(P>0){if(P&1){R=(R*B)%mod;}P>>=1;B=(B*B)%mod;}return R;}

int tre[4*M+2],lz[4*M+2];
int nxt[M+5];
map<int,int>id;
set<int>s;
int n,d,a;
vector<pi>vec;
void propagate(int pos,int l,int r)
{
    if(lz[pos]==0)return ;
    tre[pos]+=(r-l+1)*lz[pos];
    if(l!=r)
    {
        lz[2*pos]+=lz[pos];
        lz[2*pos+1]+=lz[pos];
    }
    lz[pos]=0;

}
void update(int pos,int l,int r,int I,int J,int val)
{
    propagate(pos,l,r);
    if(l>J || r<I)return;
    if(I<=l && J>=r)
    {
        lz[pos]=val;
        propagate(pos,l,r);
        return ;
    }
    int mid=(l+r)>>1;
    update(2*pos,l,mid,I,J,val);
    update(2*pos+1,mid+1,r,I,J,val);
    tre[pos]=tre[2*pos]+tre[2*pos+1];
}
int qry(int pos,int l,int  r,int I,int J)
{
    propagate(pos,l,r);
    if(l>J || r<I)
    {
        return  0;
    }
    if(I<=l && J>=r)
    {
        return tre[pos];
    }
    int mid=(l+r)>>1;
    int op1=qry(2*pos,l,mid,I,J);
    int op2=qry(2*pos+1,mid+1,r,I,J);
    tre[pos]=tre[2*pos]+tre[2*pos+1];
    return op1+op2;
}

 main()

{
    fast
    cin>>n>>d>>a;
    f(i,1,n)
    {
        int t1,t2;
        cin>>t1>>t2;
        vec.pb(mp(t1,t2));
    }
    sort(vec.begin(),vec.end());
    int j=0;
    int len=2*d;
    vec[n].fi=inf;
    f(i,0,n-1)
    {   j=max(j,i);
        while(1)
        {
            int dis=vec[i].fi+len;
            if(vec[j].fi<=dis)
            {
                j++;
            }
            else break;
        }
        nxt[i]=j-1;
    }
    int ses=0;
    f(i,0,n-1)
    {
        int lft=i;
        int rgt=nxt[i];
        //cout<<nxt[i]<<"#"<<endl;
        int bam=qry(1,0,n-1,i,i);
        if(bam>=vec[i].si)continue;
        int gap=vec[i].si-bam;
        int mov=(gap+a-1)/a;
        int val=mov*a;
        update(1,0,n-1,lft,rgt,val);
        ses+=mov;
    }
    cout<<ses<<endl;




















    return 0;

}











