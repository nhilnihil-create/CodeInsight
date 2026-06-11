#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<vector<pair<int,int>>> data(n);
    for(int i=0;i<n;i++){
        int a;
        cin >> a;
        for(int j=0;j<a;j++){
            int b,c;
            cin >> b >> c;
            data[i].push_back({b,c});
        }
    }
    int ans=0;
    for(int i=0;i<(1<<n);i++){
        //cout << "  i " << i << endl;
        bool flag=true;
        for(int j=0;j<n;j++){
            if((i>>j)&1){
                //cout << "j " << j << endl;
                for(auto x:data[j]){
                    //cout << "x.first " << x.first << " x.second " << x.second << endl;
                    if(((i>>(x.first-1))&1)!=x.second){
                        //cout << "kani" <<endl;
                        //cout << (i>>(x.first-1)) << " " << x.second << endl;
                        flag=false;
                        break;
                    }
                }
            }
            if(!flag) break;
        }
        if(flag){
            int count=0;
            for(int j=0;j<n;j++) if((i>>j)&1) count++;
            ans=max(ans,count);
            //cout << " ans " << ans << endl;
        }
    }
    cout << ans << endl;
}