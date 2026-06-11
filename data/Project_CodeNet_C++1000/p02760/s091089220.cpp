#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;

int main() {
    int t=1;
    //cin >> t;
    while(t--){
        ll n,i,j,x;
        int a[3][3];
        for(i=0;i<3;i++){
            for(j=0;j<3;j++){
                cin >> a[i][j];
               // m[a[i][j]]++;
            }
        }
        cin >> n;
        vector<int>v;
        for(i=0;i<n;i++){
            cin >> x;
            v.push_back(x);
        }
        bool vis[3][3]={false};
        for(i=0;i<3;i++){
            for(j=0;j<3;j++){
                for(int k=0;k<v.size();k++){
                    if(v[k]==a[i][j]){
                        vis[i][j]=true;
                    }
                }
            }
        }
        bool f=1,g=1,h=1,m=1,l=1,c=1,q=1,u=1;
        for(i=0;i<3;i++){
            if(!vis[0][i]){
                f=0;
            }
        }
        for(i=0;i<3;i++){
            if(!vis[2][i]){
                g=0;
            }
        }
        for(i=0;i<3;i++){
            if(!vis[1][i]){
                q=0;
            }
        }
        for(i=0;i<3;i++){
            if(!vis[i][1]){
                u=0;
            }
        }
        for(i=0;i<3;i++){
            if(!vis[i][0]){
                h=0;
            }
        }
        for(i=0;i<3;i++){
            if(!vis[i][2]){
                m=0;
            }
        }
        for(i=0;i<3;i++){
            if(!vis[i][i]){
                l=0;
            }
        }
        j=2;
        for(i=0;i<3;i++){
            if(!vis[i][j]){
                c=0;
            }
            j--;
        }
        if(f||g||h||m||l||c||u||q){
            cout <<"Yes"<<endl;
        }else{
            cout << "No"<<endl;
        }
    }
}