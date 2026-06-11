#include<bits/stdc++.h>
using namespace std;

int main(){
    int h,w;
    cin>>h>>w;
    int k;
    cin>>k;
    vector<string> s(h);

    for(int i=0;i<h;i++){
        cin>>s[i];
    }
    
    int ans = 0;
    for(int m=0;m<(1<<h);m++){
        for(int l=0;l<(1<<w);l++){
            int count = 0;
            for(int i=0;i<h;i++){
                for(int j=0;j<w;j++){
                    if((~m>>i & 1) && (~l>>j & 1) && s[i][j]=='#') count++;
                }
            }
            if(count==k) ans++;
        }
    }

    cout<<ans<<endl;
    return 0;
}