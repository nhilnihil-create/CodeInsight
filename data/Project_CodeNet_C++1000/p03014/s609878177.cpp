#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

//#define int long long
//signed main(){
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int h,w;
    cin >> h >> w;
    bool mp[h*w];
    string tmp;
    for(int i = 0; i < h; i++) {
        cin >> tmp;
        for(int j = 0; j < w; j++) {
            if(tmp[j]=='#') mp[i*w+j] = false;
            else            mp[i*w+j] = true;
        }
    }

//    for(int i = 0; i < h*w; i++) {
//        cout << mp[i];
//        if(i%w==w-1) cout << "\n";
//    }

    vector<int> r(h*w,0);
    vector<int> c(h*w,0);
    for(int i = 0; i < h; i++) {
        int cnt=0;
        for(int j = 0; j < w; j++) {
            if(mp[i*w+j]) cnt++;
            else{
                for(int k = j-cnt; k < j; k++) {
                    r[i*w+k]=cnt;
                }
                cnt=0;
            }
        }
        for(int k = w-cnt; k < w; k++) {
            r[i*w+k]=cnt;
        }
    }

    for(int j = 0; j < w; j++) {
        int cnt=0;
        for(int i = 0; i < h; i++) {
            if(mp[i*w+j]) cnt++;
            else{
                for(int k = i-cnt; k < i; k++) {
                    c[k*w+j]=cnt;
                }
                cnt=0;
            }
        }
        for(int k = h-cnt; k < h; k++) {
            c[k*w+j]=cnt;
        }
    }

//    cout << "\n";
//    for(int i = 0; i < h*w; i++) {
//        cout << r[i];
//        if(i%w==w-1) cout << "\n";
//    }

//    cout << "\n";
//    for(int i = 0; i < h*w; i++) {
//        cout << c[i];
//        if(i%w==w-1) cout << "\n";
//    }

    int ans=0;
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            int idx=i*w+j;
            if(mp[idx]) ans=max(ans,r[idx]+c[idx]-1);
            else continue;
        }
    }
    cout << ans << "\n";

    return 0;
}