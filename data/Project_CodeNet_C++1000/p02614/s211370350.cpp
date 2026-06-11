#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<iomanip>
#include <math.h>
using namespace std;
int main(){
    int h,w,x,cu=0,ans=0;
    cin>>h>>w>>x;
    vector<vector<char>> a(6, vector<char>(6));
    vector<int> b(13);

    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cin>>a[i][j];
        }
    }
    for(int i=0;i<pow(2,(h+w));i++){
        for(int j=0;j<h;j++){
            for(int k=0;k<w;k++){
                if(a[j][k]=='#'&&b[j]==0&&b[h+k]==0){
                    cu++;
                }

            }
        }
        if(cu==x){
            ans++;
        }
        cu=0;
        b[0]++;
        for(int j=0;j<h+w;j++){
            if(b[j]>1){
                b[j]=0;
                b[j+1]++;
            }
        }
        

    }
    cout<<ans<<endl;


    return 0;
}
