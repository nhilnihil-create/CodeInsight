#include<iostream>
#include<vector>
#include<string>
using namespace std;
vector<int> v;
int main(){
    string s;cin>>s;
    for(int i=0;i<(int)s.size();){
        char c=s[i];
        int cnt=0;
        while(s[i]==c){
            cnt++;
            i++;
        }
        v.push_back(cnt);
    }
    int id=0;
    vector<int> ans((int)s.size(),0);
    for(int i=0;i<(int)v.size();i+=2){
        id+=v[i];
        ans[id-1]=v[i]/2+v[i+1]/2+((v[i]&1)?1:0);
        ans[id]=v[i]/2+v[i+1]/2+((v[i+1]&1)?1:0);
        id+=v[i+1];
    }
    for(int i=0;i<(int)s.size();i++){
        cout<<ans[i]<<' ';
    }
    cout<<endl;
    return 0;
}