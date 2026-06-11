#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
using P = pair<int,int>;
using ll = long long; 

int main(){
    vector<vector<int>> data(3, vector<int>(3));
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> data.at(i).at(j);
        }
    }

    int n;
    cin>>n;
    int num;
    rep(a,n){
        cin>>num;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if(data.at(i).at(j)==num){
                    data.at(i).at(j)=0;
                }
            }
        }
    }

    bool flg=false;
    if(data.at(0).at(0)==0&&data.at(0).at(1)==0&&data.at(0).at(2)==0)flg=true;
    else if(data.at(1).at(0)==0&&data.at(1).at(1)==0&&data.at(1).at(2)==0)flg=true;
    else if(data.at(2).at(0)==0&&data.at(2).at(1)==0&&data.at(2).at(2)==0)flg=true;
    else if(data.at(0).at(0)==0&&data.at(1).at(0)==0&&data.at(2).at(0)==0)flg=true;
    else if(data.at(0).at(1)==0&&data.at(1).at(1)==0&&data.at(2).at(1)==0)flg=true;
    else if(data.at(0).at(2)==0&&data.at(1).at(2)==0&&data.at(2).at(2)==0)flg=true;
    else if(data.at(0).at(0)==0&&data.at(1).at(1)==0&&data.at(2).at(2)==0)flg=true;
    else if(data.at(2).at(0)==0&&data.at(1).at(1)==0&&data.at(0).at(2)==0)flg=true;

    if(flg==true){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }


}
