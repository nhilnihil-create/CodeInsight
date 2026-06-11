#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define con_input(v) for(auto it=v.begin();it!=v.end();it++){cin>>*it;}
#define con_debug(v) for(auto it=v.begin();it!=v.end();it++){cerr<<*it<<" ";}cerr<<endl;
using namespace std;
struct point{int x;int y;};
int i,j,k,count1=0,count2=0;

int main(){
    int x;
    cin>>x;
    if(x<100){
        cout<<0<<endl;
    }else{
        if(x>=2000){
            cout<<1<<endl;
        }else{
            int a=100,b=105,ans=0;
            for(i=1;i<=19;i++){
                if(x>=a*i&&x<=b*i)ans=1;
            }
            cout<<ans<<endl;
        }
    }
}