#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const ll INF=1LL<<60;
const int inf=1<<30;
const int mod=1e9+7;
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int h;
    while(cin >> h){
        if(h==0){
            return 0;
        }
        vector<vector<int>> a(h,vector<int>(5));
        int sum=0;
        for(int i=h-1;i>=0;i--){
            for(int j=0;j<5;j++){
                cin >> a[i][j];
                sum+=a[i][j];
            }
        }
        bool f=true;
        while(f){
            f=false;
            for(int i=0;i<h;i++){
                int cnt=1;
                for(int j=0;j<5;j++){
                    if(j){
                        if(a[i][j]>0&&a[i][j]==a[i][j-1]){
                            cnt++;
                        }
                        else{
                            if(cnt>=3){
                                for(int k=j-cnt;k<j;k++){
                                    a[i][k]=0;
                                    f=true;
                                }
                            }
                            cnt=1;
                        }
                    }
                }
                if(cnt>=3){
                    for(int j=5-cnt;j<5;j++){
                        a[i][j]=0;
                        f=true;
                    }
                }
            }
            for(int x=0;x<10;x++){
                for(int i=1;i<h;i++){
                    for(int j=0;j<5;j++){
                        if(a[i-1][j]==0){
                            a[i-1][j]=a[i][j];
                            a[i][j]=0;
                        }
                    }
                }
            }
        }
        int res=0;
        for(int i=0;i<h;i++){
            for(int j=0;j<5;j++){
                res+=a[i][j];
            }
        }
        cout << sum-res << endl;
    }
}
