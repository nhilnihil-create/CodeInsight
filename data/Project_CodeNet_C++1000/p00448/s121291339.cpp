#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define FOR(i, s, n) for(int i = s; i <= (int)n; ++i)
#define per(i, n) for(int i = n; i > 0; i--)
#define ROF(i, s, n) for(int i = s; i >= (int)n; i--)
#define FORIT(i, A) for (auto i : A)
#define PRINT(x) cout << (x) << "\n"
#define MP make_pair
#define PB push_back
#define EACH(i, n) for (__typeof((n).begin()) i = (n).begin(); i != (n).end(); ++i)
#define SZ(a) int((a).size())
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())
#define CLR(a) memset((a), 0 ,sizeof(a))
#define NCLR(a) memset((a), -1 ,sizeof(a))
#define int long long
using namespace std;
static const int INF = 1ll<<60;
int feld[15][10005];
int temp[15][10005];
int wide_white[10005];
int wide_black[10005];
int white;
int h,w;
int ans=-INF;
int v;
vector<int> tera;

void cal(int bit){
    int res=0;
    white=0;
    for(int x=0;x<=w;++x){
        wide_black[x]=0;
        wide_white[x]=0;
    }
    for(int y=1;y<=h;++y)for(int x=1;x<=w;++x)temp[y][x]=feld[y][x];
    for(int i=0;i<=h;++i){
        int b=1<<i;
        if(b&bit){
            tera.PB(i);
        }
    }
    for(int i=0;i<tera.size();++i){
        int t=tera[i];
        for(int x=1;x<=w;++x){
            temp[t][x]=!temp[t][x];
        }
    }

    /*for(int y=1;y<=h;++y){
        for(int x=1;x<=w;++x)cout<<temp[y][x];
        cout<<endl;
    }
    cout<<endl;*/
    for(int y=1;y<=h;++y){
        for(int x=1;x<=w;++x){
            if(temp[y][x]==0)white++;
        }
    }
    for(int x=1;x<=w;++x){
        for(int y=1;y<=h;++y){
            if(temp[y][x]==0)wide_black[x]++;
            else wide_white[x]++;
        }
    }
    res=white;
    for(int x=1;x<=w;++x){
        //cout<<wide_white[x]<<" "<<white<<" "<<wide_black[x]<<endl;
        res+=max(wide_white[x]-wide_black[x],0ll);
    }
    //cout<<"["<<res<<"]"<<endl;
    ans=max(ans,res);
}

signed main(){
    while(1){
        cin>>h>>w;
        if(h==0&&w==0)break;
        for(int y=1;y<=h;++y)for(int x=1;x<=w;++x)cin>>feld[y][x];
        cal(0);
        for(int i=0;i<=pow(2,h+1);++i){
            v=i;
            //cout<<i<<endl;
            tera.clear();
            cal(i);
        }
        cout<<ans<<endl;
        ans=0;
    }
}