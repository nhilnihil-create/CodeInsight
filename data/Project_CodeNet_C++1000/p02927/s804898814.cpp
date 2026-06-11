#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define con_input(v) for(auto it=v.begin();it!=v.end();it++){cin>>*it;}
#define con_debug(v) for(auto it=v.begin();it!=v.end();it++){cerr<<*it<<" ";}cerr<<endl;
using namespace std;
struct point{int x;int y;};
int i,j,k,count1=0,count2=0;

int main(){
    int m,d;
    cin>>m>>d;
    int ans=0;
    for(i=1;i<=m;i++){
        for(j=1;j<=d;j++){
            if(j%10>=2&&j/10>=2&&(j%10)*(j/10)==i){
                cerr<<i<<" "<<j<<endl;
                ans++;
            }
        }
    }
    cout<<ans<<endl;
}
