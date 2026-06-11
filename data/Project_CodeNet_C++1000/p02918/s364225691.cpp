#include <iostream>
#include <vector>
using namespace std;

int main(){
        int n,k,i,cnt=0,ans=0;
        char s_pre,s_now;
        cin >> n >> k;
        cin >> s_pre;
        for(i=0;i<n-1;++i){
                cin >> s_now;
                if(s_pre=='R'&&s_now=='L') ++cnt;
                else if(s_pre==s_now) ++ans;
                s_pre = s_now;
        }
        /*if(k<cnt) ans += k*2;
        else ans += cnt*2 + 1;*/
        cout << min(ans+2*k,n-1) << endl;
        return 0;
}