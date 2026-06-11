#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define con_input(v) for(auto it=v.begin();it!=v.end();it++){cin>>*it;}
#define con_debug(v) for(auto it=v.begin();it!=v.end();it++){cerr<<*it<<" ";}cerr<<endl;
using namespace std;
struct point{int x;int y;};
int i,j,k,count1=0,count2=0;

int main(){
    int n;
    cin>>n;
    vector<double> vec(n);
    con_input(vec);
    sort(all(vec));
    double ans=0;
    for(i=0;i<n;i++){
        if(i==0)ans=vec[i];
        else {
            ans=(ans+vec[i])/2;
        }
    }
    printf("%.8lf\n",ans);
}