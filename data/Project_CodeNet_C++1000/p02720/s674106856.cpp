#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1000000007;
#define INF 1LL<<30
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()

vector<ll> lun;

void dfs(string s){
    int x=s.back()-'0';
    lun.push_back(stoll(s));
    if(s.size()>11) return;
    if(x==0){
        dfs(s+"0");
        dfs(s+"1");
    }
    else if(x==1){
        dfs(s+"0");
        dfs(s+"1");
        dfs(s+"2");
    }
    else if(x==2){
        dfs(s+"1");
        dfs(s+"2");
        dfs(s+"3");
    }
    else if(x==3){
        dfs(s+"2");
        dfs(s+"3");
        dfs(s+"4");
    }
    else if(x==4){
        dfs(s+"3");
        dfs(s+"4");
        dfs(s+"5");
    }
    else if(x==5){
        dfs(s+"4");
        dfs(s+"5");
        dfs(s+"6");
    }
    else if(x==6){
        dfs(s+"5");
        dfs(s+"6");
        dfs(s+"7");
    }
    else if(x==7){
        dfs(s+"6");
        dfs(s+"7");
        dfs(s+"8");
    }
    else if(x==8){
        dfs(s+"7");
        dfs(s+"8");
        dfs(s+"9");
    }
    else if(x==9){
        dfs(s+"8");
        dfs(s+"9");
    }
    


}

int main(){
    dfs("1");
    dfs("2");
    dfs("3");
    dfs("4");
    dfs("5");
    dfs("6");
    dfs("7");
    dfs("8");
    dfs("9");

    sort(all(lun));
    
    int k;
    cin>>k;

    //rep(i,15) cout<<lun[i]<<" ";
    //cout<<endl;
    cout<<lun[k-1]<<endl;
}

