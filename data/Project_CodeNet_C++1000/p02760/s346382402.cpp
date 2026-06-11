#include<bits/stdc++.h>
using namespace std;
typedef long long int INT;

int main()
{
    vector<vector<int>> a(3,vector<int>(3));
    for (int i=0;i<3;i++){
        for (int j=0;j<3;j++){
            cin>>a.at(i).at(j);
        }
    }
    int n;
    cin>>n;

    vector<int> b(n);
    for (int i=0;i<n;++i){
        cin>>b.at(i);
    }
    for (int i=0;i<3;++i){
        for (int j=0;j<3;++j){
            for (int k=0;k<n;++k){
                if(a.at(i).at(j)==b.at(k)){
                    a.at(i).at(j)=0;
                }
            }
        }
    }
    string ans="No";
    for (int i=0;i<3;i++){
        if(a.at(i).at(0)==0&&a.at(i).at(1)==0&&a.at(i).at(2)==0){
            ans="Yes";
            break;
        }
    }
    for (int i=0;i<3;i++){
        if(a.at(0).at(i)==0&&a.at(1).at(i)==0&&a.at(2).at(i)==0){
            ans="Yes";
            break;
        }
    }
    if(a.at(0).at(0)==0&&a.at(1).at(1)==0&&a.at(2).at(2)==0){
        ans="Yes";
    }
    if(a.at(0).at(2)==0&&a.at(1).at(1)==0&&a.at(2).at(0)==0){
        ans="Yes";
    }
    cout<<ans<<endl;

}