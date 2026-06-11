#include<bits/stdc++.h>
using namespace std;

int main(){
    int m,d,ans=0;
    cin >> m >> d;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=d;j++){
            if(j<=19)continue;
            else{
                if(j%10>=2)
                {
                    if(i==(j/10)*(j%10))ans++;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}