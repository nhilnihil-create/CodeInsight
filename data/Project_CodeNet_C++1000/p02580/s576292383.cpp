#include<bits/stdc++.h>

using namespace std;
typedef         long long int   ll;


#define         input           freopen("input.txt","r",stdin)
#define         output          freopen("output.txt","w",stdout)
#define         si(a)           scanf("%d",&a)
#define         sii(a,b)        scanf("%d%d",&a,&b)
#define         siii(a,b,c)     scanf("%d%d%d",&a,&b,&c)
#define         pi(a)           printf("%d",a)
#define         spc             printf(" ")
#define         bl              printf("\n")
#define         here(a)         printf("#### %d ####",a)
#define         pii             pair<int,int>
#define         fr(i,n)         for(int i=0;i<n;i++)
#define         case(num)       printf("Case %d:",num)
#define         inf             1000000050
#define         MAX             100010*3

int row[MAX+10],column[MAX+10];
vector<pii>v;
vector<int>pr,pc;
int main(){

    //input;
    //output;

    int h,w,m,x,y;
    cin>>h>>w>>m;
    int mr,mc;
    mr = -1; mc = -1;
    for(int i=0;i<m;i++){
        cin>>x>>y;
        row[x]++;
        column[y]++;
        mr = max(mr,row[x]);
        mc = max(mc,column[y]);
        v.push_back(pii(x,y));
    }
    int l = max(h,w);

    for(int i=0;i<=l;i++){
        if(row[i]==mr) pr.push_back(i);
        if(column[i]==mc) pc.push_back(i);
    }

    int ans = mr+mc;
    int flag = 1;
    sort(v.begin(),v.end());

    for(int i=0;i<pr.size();i++){
        for(int j=0;j<pc.size();j++){
            /// search if the poing is exist
            int pos = lower_bound(v.begin(),v.end(),pii(pr[i],pc[j]))- v.begin();
            if(pos>=v.size()){
                flag = 0;
                break;
            }
            if(v[pos].first!=pr[i] || v[pos].second!=pc[j]){
                flag = 0;
                break;
            }
        }
    }

    //cout<<endl;
    //cout<<pr<<" "<<pc<<endl;
    cout<<ans-flag<<endl;

    return 0;
}
/**
*/
