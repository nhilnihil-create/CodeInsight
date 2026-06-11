#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
using namespace std;
typedef long long ll;
int INF = (1LL << 30) - 1;
int MOD = 1e9+7;
main(){
    int N;
    cin >> N;
    while(N){
        int flag = 0,used = 0,cnt = 0;//下についている := 0 左足2,右足1
        rep(i,0,N){
            string s;
            cin >> s;
            if(!flag){
                if(s == "lu")used += 2;
                if(s == "ru")used += 1;
                if(s == "ld")used -= 2;
                if(s == "rd")used -= 1;
            }else{
                if(s == "ld")used += 2;
                if(s == "rd")used += 1;
                if(s == "lu")used -= 2;
                if(s == "ru")used -= 1;
            }
            if(used == 3){
                used = 0;
                flag = !flag;
                cnt++;
            }
        }
        cout << cnt << endl;
        cin >> N;
    }
}
