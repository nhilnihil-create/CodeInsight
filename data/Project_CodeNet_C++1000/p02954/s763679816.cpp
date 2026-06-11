#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main(){
    string s;
    cin>>s;

    int n=s.size();
    vector<int> ans(n,0);
    int cnt=0;
    for(int i=0;i<n;++i){
        if(s[i]=='L'){
            if(cnt%2==1){
                ans[i-1]+=cnt/2+1;
                ans[i]+=cnt/2;
            }
            else{
                ans[i]+=cnt/2;
                ans[i-1]+=cnt/2;
            }
            cnt=0;
        }
        else ++cnt;
    }
    /*
    cout<<"R: "<<endl;
    for(int i=0;i<n;++i) cout<<ans[i]<<' ';
    cout<<endl;
    */
    cnt=0;
    for(int i=n-1;i>=0;--i){
        if(s[i]=='R'){
            if(cnt%2==1){
                ans[i+1]+=cnt/2+1;
                ans[i]+=cnt/2;
            }
            else{
                ans[i]+=cnt/2;
                ans[i+1]+=cnt/2;
            }
            cnt=0;
        }
        else ++cnt;
    }

    for(int i=0;i<n;++i) cout<<ans[i]<<' ';
    cout<<endl;
}