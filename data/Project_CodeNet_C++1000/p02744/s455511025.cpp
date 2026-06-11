#include "bits/stdc++.h"
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll =long long;
using P =pair<int,int>;

int n;

vector <string> ans;

void dfs(string s,int x){
    int l;
    int xx;
    l=s.size();
    if(l==n){
        ans.push_back(s);
    }
    else{
        char a;
        a='a';
        rep(i,x){
            if(i==0){
                a='a';
            }
            else if(i==1){
                a='b';
            }
            else if(i==2){
                a='c';
            }
            else if(i==3){
                a='d';
            }
            else if(i==4){
                a='e';
            }
            else if(i==5){
                a='f';
            }
            else if(i==6){
                a='g';
            }
            else if(i==7){
                a='h';
            }
            else if(i==8){
                a='i';
            }
            else if(i==9){
                a='j';
            }
            //xx=max(x,)
            xx=x;
            if(i==x-1){
                xx=x+1;
            }
            
            
            
            string ss;
            ss=s+a;
            dfs(ss,xx);
        }
    }
}

int main(){
    cin >> n;
    string aa;
    aa='a';
    dfs(aa,2);

    sort(ans.begin(),ans.end());

    int l2;
    l2=ans.size();

    

    rep(i,l2){
        cout << ans[i] << endl;
    }
    
    

    return 0;
}