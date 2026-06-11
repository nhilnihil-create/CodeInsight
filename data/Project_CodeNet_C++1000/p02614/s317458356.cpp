#include<iostream>
#include<vector>
using namespace std;

int main(){
    int h,w,k;
    cin>>h>>w>>k;
    vector<string> v(h);
    for(int i=0;i<h;i++) cin>>v[i];

    int ans=0;
    for(int i=0;i<(1<<h);i++){
        for(int j=0;j<(1<<w);j++){
            int c=0;
            for(int k=0;k<h;k++){
                for(int l=0;l<w;l++){
                    if((i&(1<<k))&&(j&(1<<l))&&v[k][l]=='#') c++;
                }
            }
            if(c==k) ans++;
        }
    }
    cout<<ans<<endl;
}