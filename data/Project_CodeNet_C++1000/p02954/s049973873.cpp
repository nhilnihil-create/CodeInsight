#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <map>
#define ll long long
using namespace std;
int main(){
    string s;
    cin>>s;
    vector<int> ans(s.length());
    int rcnt=0;
    for(int i=0;i<s.length();i++){
        if(s[i]=='R'){
            rcnt++;
        }else{
            int evenr=rcnt/2;
            int oddr=rcnt-evenr;
            ans[i]+=evenr;
            ans[i-1]+=oddr;
            rcnt=0;
        }
    }
    int lcnt=0;
    for(int i=s.length();i>=0;i--){
        if(s[i]=='L'){
            lcnt++;
        }else{
            int evenl=lcnt/2;
            int oddl=lcnt-evenl;
            ans[i]+=evenl;
            ans[i+1]+=oddl;
            lcnt=0;
        }
    }

    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}