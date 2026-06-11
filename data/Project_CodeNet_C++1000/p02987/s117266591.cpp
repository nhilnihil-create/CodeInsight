#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef unsigned long long int ulli;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int,int> pii;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define YN(x) cout<<(bool x?"Yes":"No")<<endl;
#define out(s) cout<<s<<endl;
#define pb push_back;
#define sp " ";
void vout(vector<int> v){
    for(int i=0;i<v.size();i++)
    cout<<v.at(i)<<endl;
}
int main(){
    string s;
    cin>>s;
    bool c=true;
    map<char,int> ans;
    rep(i,4){
        if(ans.count(s.at(i))){
            ans.at(s.at(i))+=1;
        }
        else{
            ans[s.at(i)]=1;
        }
    }
    if(ans.size()!=2) c=false;
    for(auto v:ans){
        if(v.second!=2) c=false;
    }
cout<<(c?"Yes":"No")<<endl;

}