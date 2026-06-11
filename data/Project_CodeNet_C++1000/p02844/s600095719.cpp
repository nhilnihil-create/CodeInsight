#include <iostream>
#include <string>
#define rep(i, n)for(int i=0; i<n; i++)
using namespace std;

int main(){
    int n;
    string s;
    cin >> n >> s;

    int num[1000]{};
    rep(i,1000){
        string strint = to_string(i);
        if(i<10){
            strint[2] = strint[0];
            strint[0] = strint[1] = '0';
        }else if(i<100){
            strint[2] = strint[1];
            strint[1] = strint[0];
            strint[0] = '0';
        }
        bool flag[3] {};
        int j=0;
        rep(k, n){
            if(s[k]==strint[j]){
                flag[j] = 1;
                j++;
            } 
        }
        if(flag[0]==1 && flag[1]==1 && flag[2]==1){
            num[i] =1;
        }
    }

    int ans=0;
    rep(i,1000){
        if(num[i]==1) ans++;
    }

    cout << ans << endl;
    
    return 0;
}
