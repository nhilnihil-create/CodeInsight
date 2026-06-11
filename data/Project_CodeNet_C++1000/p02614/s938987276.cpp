#include <bits/stdc++.h>
using namespace std;
#define INF 1e9+7
typedef long long int ll;
const int maxn =1000000; 
ll mod = INF;
int h,w,k;
char g[10][10];
int ans=0;
bool use[12]={0};

void func(int cnt=0){
    if(cnt==h+w){
        // for(int i=0;i<h+w;i++)cout << use[i];
        // cout << endl;
        char m[10][10];
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                m[i][j]=g[i][j];
            }
        }
        for(int i=0;i<h;i++){
            if(use[i]){
                for(int j=0;j<w;j++)m[i][j]='.';
            }
        }
        for(int i=h;i<h+w;i++){
            if(use[i]){
                for(int j=0;j<h;j++)m[j][i-h]='.';
            }
        }
        int count=0;
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                if(m[i][j]=='#')count++;
            }
        }
        if(k==count)ans++;
    }else{
        use[cnt]=true;
        func(cnt+1);
        use[cnt]=false;
        func(cnt+1);
    }
    return;
}

int main(){

    cin >> h>>w>>k;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cin >> g[i][j];
        }
    }

    func();

    cout << ans<<endl;
    
    return 0;
}