#include<bits/stdc++.h>

using namespace std;

int H, W, A, B;

int ans[1005][1005];

int main(){
    cin>>H>>W>>A>>B;

    for(int i=1;i<=H;++i){
        for(int j=1;j<=W;++j){
            if((i<=B&&j<=A)||(i>B&&j>A)){
                cout<<"1";
            }else{
                cout<<"0";
            }
        }
        cout<<endl;
    }

    return 0;
}
