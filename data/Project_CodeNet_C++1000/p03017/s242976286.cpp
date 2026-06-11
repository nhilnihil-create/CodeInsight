#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define ll long long int
#define INF 1000000007
#define llINF 1000000000000000007
#define v(i) vector<i>
#define vv(i) vector<vector<i>>
// cin.eof() 入力個数の問題
// int num = atoi(string.c_str()); 文字列の整数変換
int keta(ll n){int ans=0;while(n>0){n /= 10; ans++;}return ans;}
ll _pow(ll a,ll b){ll ans = 1;rep(i,b){ ans *= a;}return ans;}

int main() {
    int n,a,b,c,d;
    cin>>n>>a>>b>>c>>d;
    string s; cin >> s;
    bool flag = false;
    int count =0;
    //if(s[0] == '.')count++;
    for(int i = a;i < c;i++){
       
        if(s[i] == '#' &&s[i-1] == '#'){
            cout<<"No"<<endl;
            return 0;
        }
        
    }
    for(int i = b;i < d;i++){
       
        if(s[i] == '#' &&s[i-1] == '#'){
            cout<<"No"<<endl;
            return 0;
        }
        
    }
    for(int i = b-2;i <= d;i++){
         if(s[i] == '.'){
            count++;
        }else
        {
            count = 0;
        }
        if(count == 3){
            flag = true;
        }
    }
    if(c<d){
        cout<<"Yes"<<endl;
        return false;
    }else
    {
        if(flag){
    cout<<"Yes"<<endl;
    }else
    {
        cout<<"No"<<endl;
    }
    
    }
    
    return 0;
}
