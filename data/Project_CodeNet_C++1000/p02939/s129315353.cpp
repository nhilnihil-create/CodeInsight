#include <bits/stdc++.h>
#define f(i,j,k) for(int i=j;i<k;i++)
using namespace std;
int main(){
    long long ans=0;
    string s,now="",pre="";
    cin>>s;
    f(i,0,s.size()){
        now.push_back(s[i]);
        if(now!=pre){
            pre=now;
            now="";
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}
