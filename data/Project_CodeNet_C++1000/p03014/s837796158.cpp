#include <bits/stdc++.h>
using namespace std;
int main(){
    int H,W;
    cin>>H>>W;
    vector<string> vec(H);
    vector<vector<int>> vec1(H,vector<int>(W));
    vector<vector<int>> vec2(H,vector<int>(W));
    for(int i=0;i<H;i++){
        string S;
        cin>>S;
        vec.at(i)=S;
        int j=0,L=0;
        while(j!=W){
            if(S.at(j)=='#'){
                if(j==0){
                    j++;
                    L=1;
                    continue;
                }
                for(int k=L;k<j;k++){
                    vec1.at(i).at(k)=j-L;
                }
                L=j+1;
                j++;
                continue;
            }
            j++;
            if(j==W){
                for(int k=L;k<j;k++){
                    vec1.at(i).at(k)=j-L;
                }
                break;
            }
        }
    }
    for(int i=0;i<W;i++){
        int j=0,L=0;
        while(j!=H){
            string S=vec.at(j);
            if(S.at(i)=='#'){
                if(j==0){
                    j++;
                    L=1;
                    continue;
                }
                for(int k=L;k<j;k++){
                    vec2.at(k).at(i)=j-L;
                }
                L=j+1;
                j++;
                continue;
            }
            j++;
            if(j==H){
                for(int k=L;k<j;k++){
                    vec2.at(k).at(i)=j-L;
                }
                break;
            }
        }
    }
    int ans=0;
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            ans=max(ans,max(0,vec1.at(i).at(j)+vec2.at(i).at(j)-1));
        }
    }
    cout<<ans<<endl;
}