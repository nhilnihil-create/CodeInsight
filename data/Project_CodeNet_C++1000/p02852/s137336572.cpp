#include<cstdio>
#include<math.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<set>
#include<cstring>
#include<map>
 
 
using namespace std;
#define int long long int
#define rep(i,n) for(int i=0;i<n;i++)
#define INF 1001001001
#define LLINF 1001001001001001001
#define mp make_pair
#define pb push_back
#define mod 1000000007

int N,M;
char S[100005];
vector<int> ans;
signed main(){
    scanf("%lld %lld",&N,&M);
    scanf("%s",S);
    //後ろから辿っていく
    int point=N;
    int last_ok_point=N;
    for(int i=N-1;i>=0;i--){
        if(S[i]=='0')last_ok_point=i;
        if(point-i==M||i==0){
            if(point-last_ok_point>0){
                ans.pb(point-last_ok_point);
                point=last_ok_point;
            }
            else{printf("-1\n");return 0;}
        }
    }
    for(int i=ans.size()-1;i>=0;i--){
        printf("%lld",ans[i]);
        if(i!=0)printf(" ");
        else  printf("\n");
    }
    return 0;
}
