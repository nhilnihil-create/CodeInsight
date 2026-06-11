#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int inf = 1e9;

int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = 0;
    
    for(int i=0;i<1000;i++){
        string t = "000";
        if(0 < i &&i < 10){
            t[2] = '0' + i;
        }
        else if(i < 100){
            t[1] = '0' + i/10;
            t[2] = '0' + i%10;           
        }else{
            t[0] = '0' + i/100;
            t[1] = '0' + (i/10)%10;
            t[2] = '0' + i%10;
        }

        bool exist = false;

        for(int a=0;a<n-2;a++){
            if(s[a] == t[0]){
                for(int b=a+1;b<n-1;b++){
                    if(s[b] == t[1]){
                        for(int c=b+1;c<n;c++) if(s[c] == t[2]) exist = true;
                        break;
                    }
                }
                break;
            }
        }

        if(exist) ans++;
    }
 
    cout << ans << endl;
}
