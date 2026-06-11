#include <bits/stdc++.h>
using namespace std;
#define lson rt<<1
#define rson rt<<1|1
#define scd(x) scanf("%d",&x)
#define scdd(x,y) scanf("%d%d",&x,&y)
const int maxn=3e5+10;
typedef long long ll;
typedef pair<int,int> pii;
const int INF=0x3f3f3f3f;
int arr[maxn],sum[maxn*4],val[maxn*4];
void push_up(int rt) {
    int l=lson,r=rson;
    sum[rt]=sum[l]+sum[r];
    val[rt]=min(val[l],val[r]);
}
void build(int rt,int l,int r) {
    if(l==r) {
        sum[rt]=1;
        val[rt]=l;
        return ;
    }
    int mid=(l+r)/2;
    build(lson,l,mid);
    build(rson,mid+1,r);
    push_up(rt);
}
void update(int rt,int l,int r,int pos) {
    if(l==r) {
        sum[rt]=0;
        val[rt]=INF;
        return ;
    }
    int mid=(l+r)/2;
    if(pos<=mid)update(lson,l,mid,pos);
    else update(rson,mid+1,r,pos);
    push_up(rt);
}
pii query(int rt,int l,int r,int ql,int qr) {
    if(ql<=l&&qr>=r) {
        return pii(sum[rt],val[rt]);
    }
    int mid=(l+r)/2;
    pii ans=pii(0,0);
    if(ql<=mid)ans=query(lson,l,mid,ql,qr);
    if(qr>mid&&ans.first==0)ans=query(rson,mid+1,r,ql,qr);
    return ans;
}
vector<int>vec;
multiset<int>s;
int find_pos(int x,int l,int r){
    int ans=-1;
    while(r>=l){
        int mid=(l+r)/2;
        if(arr[mid]>=x){
            ans=mid;
            l=mid+1;
        }
        else r=mid-1;
    }
    return ans;
}
int main() {
#ifdef LOCAL
    freopen("in.txt","r",stdin);
#endif // LOCAL
    int n;
    //cout<<(1<<18)<<endl;
    scd(n);
    int la=1<<n;
    for(int i=1; i<=la; i++) {
        scd(arr[i]);
        s.insert(arr[i]);
    }
    sort(arr+1,arr+la+1,greater<int>() );
   // build(1,1,la);
    bool flag=false;
    vec.clear();
    vec.push_back(arr[1]);
    //update(1,1,la,1);
    multiset<int>::iterator it=s.lower_bound(arr[1]);
    s.erase(it);
    while(!flag) {
        if(vec.size()==la) {
            flag=true;
            break;
        }
        int siz=vec.size();
        //sort(vec.begin(),vec.end(),greater<int>() );
        //cout<<"?"<<endl;
        for(int i=0; i<siz; i++) {
//            int pos=find_pos(vec[i],1,la);
//            if(pos==la){
//                flag=true;break;
//            }
//            pii ans=query(1,1,la,pos+1,la);
//            if(ans.first==0){
//                flag=true;break;
//            }
//            update(1,1,la,ans.second);

            multiset<int>::iterator it = s.lower_bound(vec[i]);
            if(it==s.begin()){
                flag=true;break;
            }
            it--;
            vec.push_back(*it);
            s.erase(it);
        }
    }
    if(vec.size()==la)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}
