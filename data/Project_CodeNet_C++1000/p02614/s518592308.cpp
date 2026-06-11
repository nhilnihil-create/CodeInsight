#include<bits/stdc++.h>
using namespace std;
#define lint long long
#define inf 100000000000000000
#define mod 1000000007
#define MAX 100005
#define pb push_back
#define vit vector<int>::iterator
typedef pair<int,int> pii;
map<string,int>M;
vector<int> V[MAX];
string S[MAX];
int checkbit(int n,int bit){ /// bit 0 index
    return (n>>bit)&1;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int h,w,k,ans=0;
    cin>>h>>w>>k;
    for(int i=0;i<h;i++) cin>>S[i];
    for(int i=0;i<(1<<h);i++){
        for(int j=0;j<(1<<w);j++){
            int sum=0;
            for(int x=0;x<h;x++){
                for(int y=0;y<w;y++){
                    if(!checkbit(i,x) && !checkbit(j,y) && S[x][y]=='#')
                        sum++;
                }
            }
            if(sum==k) ans++;
        }
    }
    cout<<ans;
    return 0;
}
