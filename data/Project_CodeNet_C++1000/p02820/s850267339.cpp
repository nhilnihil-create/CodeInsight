#include <bits/stdc++.h>
using namespace std;
int n,k,r,s,p;
string t;
int getPoint(char c){
    switch(c){
        case 'r':
            return p;
            break;
        case 's':
            return r;
            break;
        case 'p':
            return s;
            break;
    }
}
int main(){
    cin >> n >> k; 
    cin >> r >> s >> p; 
    cin >> t;
    vector <int> eachPoint(n);
    for(int i = 0; i < n; i++){
        eachPoint[i] = getPoint(t[i]);
    }
    //どの勝負を捨てるか選ぶ。
    //n/k個の組について考える。
    vector <int> dp(n,-1);
        //毎回t[i]が変わるなら全部勝てる。
        //t[i]が連続する区間はどれを捨てるか考える。
        //基本的には捨てる勝負が少ない方が望ましい。
        //奇数個連続する場合は、偶数個目を捨てる。
        //偶数個目についてはどちらでもよい。
        {
            int index = 0;
            char lastValue = t[index];
            while(index<n){
                int index2 = index+k;
                if(dp[index]==-1){
                    while(index2<n){
                        if(t[index]==t[index2]){
                            if(dp[index]==-1){
                                dp[index]=0;
                            }
                            dp[index2]=0;
                            dp[index]++;
                        }else{
                            break;
                        }
                        index2+=k;
                    }
                }
                index++;
            }
        }
        #if 0

        for(int i = 0; i < n; i++){
            cout << t[i] << " ";
        }
        cout << endl;
        for(int i = 0; i < n; i++){
            cout << dp[i] << " ";
        }
        cout << endl;
        #endif
        {
            int index = 0;
            while(index < n){
                if(dp[index]==0){
                    index++;
                }else if(dp[index]==-1){
                    index++;
                }else{
                    int index2 = index;
                    int cnt = 1;
                    while(index2<=index+k*dp[index]){
                        if(index2<n){
                            if(cnt%2==0){
                                eachPoint[index2]=0;
                            }
                            cnt++;
                            index2+=k;
                        }else{
                            break;
                        }
                    }
                    index++;
                }
            }
            long ans = 0;
            for(int i = 0; i < n; i++){
                ans+=eachPoint[i];
            }
            cout << ans << endl;
        }
        #if 0
        for(int i = 0; i < n; i++){
            cout << t[i];
            if(i%k==k-1){
                cout << endl;
            }
        }
        cout << endl;
        for(int i = 0; i < n; i++){
            cout << dp[i];
            if(i%k==k-1){
                cout << endl;
            }
        }
        cout << endl;
        #endif

    return 0;
}