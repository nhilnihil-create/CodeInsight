#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int x[111]={0},y[111]={0};
vector<pair<int,int>>mm[16];
int n;
int sta[16]={0};
int solve(int num){
    for(int i=1;i<=n;i++,num/=2)
        sta[i]=num%2;
    for(int i=1;i<=n;i++){
        int flag = 1 ;
        for(auto pp:mm[i]){
            if(sta[pp.first]!=pp.second)
                flag = 0;
        }
        if(flag != sta[i])
            return 0;
    }
    int ret =0 ;
    for(int i=1;i<=n;i++)
        ret+=sta[i];
    return ret;
}
int main()
{
    //cout << (1<<15) << endl;
    cin >> n;
    for(int i=1;i<=n;i++){
        int num,a,b;
        cin >> num;
        while(num--){
            cin >>a >> b;
            mm[i].push_back({a,b});
        }
    }
    int ans = 0 ;
    for(int i=0;i<(1<<n);i++){
        //cout <<
        ans = max(ans,solve(i));
    }
    cout << ans << endl;
    return 0;
}
